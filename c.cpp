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


#ifdef umang99m
#include "/home/umang/.templates/header.h"
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

    mytype po(mytype x, lli y){
        mytype ans = 1;
        fo(i,y){
            ans *= x;
        }
        return ans;
    }
void run()
{
    vi libcost;
    vector<bool> visl(l,false),visb(b,false);

    lli myscr=0;
    cout<<l<<endl;
    lli nl=0;
    for(nl=0;nl<l;++nl)
    {
        if(d<0)
            break;
        lli ans=-1;
        mytype bstscr=-1, b1=-1, bestb1=-1;
        for(lli i=0;i<l;++i)
        {
            if(visl[i]||d<=libd[i].X)
                continue;
            lli cnt=0,sc=(d-libd[i].X)*libd[i].Y;
            const vi &cur=library[i];
            for(auto x:cur)
            {
                if(sc<=0)
                    break;
                if(visb[x])
                    continue;
                cnt+=bcost[x];
                sc--;
            }
            mytype mycnt = cnt, mylibd = libd[i].X;

            b1 = po(mycnt,161)/po(mylibd,160);
            if(b1 > bestb1)
            {
                ans=i;
                bestb1 = b1;
            }
        }

        if(ans==-1)
            break;

            vi prt;
            lli sc=(d-libd[ans].X)*libd[ans].Y;
            const vi &cur=library[ans];
            for(auto x:cur)
            {
                if(sc<=0)
                    break;
                if(visb[x])
                    continue;
                sc--;
                prt.pb(x);
                visb[x]=true;
            }
        //dbg(libd[ans]);
        visl[ans]=true;
        if(prt.empty())
            prt.pb(cur[0]);
        assert(!prt.empty());
        cout<<ans<<" "<<sz(prt)<<endl;
        for(auto x:prt){
         cout<<x<<" ";
         myscr += bcost[x];
        }
        cout<<endl;
        d-=libd[ans].X;
    }

    dbg("lib signup",nl);
    // cout<<"Hello"<<endl;
    for(lli i=0;i<l;++i)
    {
        if(visl[i])
            continue;
        cout<<i<<" "<<1<<endl;
        cout<<library[i][0]<<endl;
    }

    cerr<<"MY SCORE "<<myscr/1000000.0<<endl;
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
}
    return 0;
}

