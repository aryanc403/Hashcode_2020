/*
  Compete against Yourself.
  Author - Aryan Choudhary (@aryanc403)
*/

#pragma GCC optimize ("Ofast")
#pragma GCC target ("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize ("-ffloat-store")

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
#define fo(i,n)   for(i=0;i<(n);++i)
#define repA(i,j,n)   for(i=(j);i<=(n);++i)
#define repD(i,j,n)   for(i=(j);i>=(n);--i)
#define all(x) begin(x), end(x)
#define sz(x) (lli)(x).size()
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define endl "\n"

typedef long long int lli;
typedef long double mytype;
typedef pair<lli,lli> ii;
typedef vector<ii> vii;
typedef vector<lli> vi;

clock_t time_p=clock();
void aryanc403()
{
#ifdef ARYANC403
    time_p=clock()-time_p;
    cerr<<"Time Taken : "<<(float)(time_p)/CLOCKS_PER_SEC<<"\n";
#endif
}

#ifdef ARYANC403
#include "/home/aryan/codes/PastCodes/header.h"
#else
    #define dbg(args...)
#endif

const lli INF = 0xFFFFFFFFFFFFFFFL;

lli seed;
mt19937 rng(seed=chrono::steady_clock::now().time_since_epoch().count());
inline lli rnd(lli l=0,lli r=INF)
{return uniform_int_distribution<lli>(l,r)(rng);}

class CMP
{public:
bool operator()(ii a , ii b) //For min priority_queue .
{    return ! ( a.X < b.X || ( a.X==b.X && a.Y <= b.Y ));   }};

void add( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt==m.end())         m.insert({x,cnt});
    else                    jt->Y+=cnt;
}

void del( map<lli,lli> &m, lli x,lli cnt=1)
{
    auto jt=m.find(x);
    if(jt->Y<=cnt)            m.erase(jt);
    else                      jt->Y-=cnt;
}

bool cmp(const ii &a,const ii &b)
{
    return a.X<b.X||(a.X==b.X&&a.Y<b.Y);
}

const lli mod = 1000000007L;
// const lli maxN = 1000000007L;

    lli T,n,i,j,k,in,cnt,l,r,u,v,x,y;
    lli m,b,d,t;
    string s;
    vi bcost;
    // vector<vi> bookedge;
    vector<vi> library;
    vii libd;
    //priority_queue < ii , vector < ii > , CMP > pq;// min priority_queue .

lli solve(const vi &a,lli d)
{
    vector<bool> visb(b,false);
    lli scr=0;
    for(auto &ans:a)
    {
        if(d<0)
            break;
        if(d<libd[ans].X)
            continue;
        
            lli sc=(d-libd[ans].X)*libd[ans].Y;
            const vi &cur=library[ans];
            for(auto x:cur)
            {
                if(sc<=0)
                    break;
                if(visb[x])
                    continue;
                visb[x]=true;
                scr+=bcost[x];
            }
        d-=libd[ans].X;
    }
    dbg(scr);
    return scr;
}

void prt()
{
vector<bool> visb(b,false);
    lli scr=0;
    for(auto &ans:a)
    {
        if(d<0)
            break;
        if(d<libd[ans].X)
            continue;
        
            lli sc=(d-libd[ans].X)*libd[ans].Y;
            const vi &cur=library[ans];
            for(auto x:cur)
            {
                if(sc<=0)
                    break;
                if(visb[x])
                    continue;
                visb[x]=true;
                scr+=bcost[x];
            }
        d-=libd[ans].X;
    }
    dbg(scr);
    return scr;
}

void run()
{
    vi libcost;
    vector<bool> visl(l,false),visb(b,false);

    vi a;
    for(lli i=0;i<l;++i)
        a.pb(i);
    vi ans;
    lli myscr=-1;
    for(lli kk=0;kk<10000;++kk)
    {
        shuffle(all(a),rng);
        lli cnt=solve(a,d);
        // dbg(a);
        if(cnt>myscr)
        {
            myscr=cnt;
            ans=a;
        }
    }

    cerr<<"MY SCORE "<<myscr/1000000.0<<endl;
    prt();

    // assert(false);    
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    // freopen("c_inp.txt", "r", stdin);
    // freopen("d_ana_cost.txt", "w", stdout);
// cout<<std::fixed<<std::setprecision(35);
// cin>>T;while(T--)
{

    cin>>b>>l>>d;
    bcost.resize(b);
    // bookedge.resize(b);

    for(auto &x:bcost)
        cin>>x;

    fo(i,l)
    {
        cin>>n>>t>>m;
        libd.pb({t,m});
        vi cur;
        cur.resize(n);
        for(auto &x:cur)
        {
            cin>>x;
            // bookedge[x].pb(i);
        }
        sort(all(cur),[&](const lli aa,const lli bb){
            return bcost[aa]>bcost[bb];
        });
        library.pb(cur);
    }

    run();
}   aryanc403();
    return 0;
}
