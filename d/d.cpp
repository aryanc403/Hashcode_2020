//Utkarsh.25dec
#include <bits/stdc++.h>
#include <chrono>
#include <random>
#define ll long long int
#define ull unsigned long long int
#define pb push_back
#define mp make_pair
#define mod 1000000007
#define rep(i,n) for(ll i=0;i<n;i++)
#define loop(i,a,b) for(ll i=a;i<=b;i++)
#define vi vector <int>
#define vs vector <string>
#define vc vector <char>
#define vl vector <ll>
#define all(c) (c).begin(),(c).end()
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
using namespace std;
ll power(ll a,ll b) {ll res=1;a%=mod; assert(b>=0); for(;b;b>>=1){if(b&1)res=res*a%mod;a=a*a%mod;}return res;}
ll modInverse(ll a){return power(a,mod-2);}
const int N=500023;
bool vis[N];
vector <int> adj[N];
vector <int> present[N];
void solve()
{
    ll b,l,d;
    cin>>b>>l>>d;
    set <pair<ll,ll>> lib;
    set <pair<ll,ll>> libinv;
    vl score;
    for(int i=0;i<b;i++)
    {
        ll c;
        cin>>c;
        score.pb(c);
    }
    for(int i=0;i<l;i++)
    {
        ll n,t,m;
        cin>>n>>t>>m;
        // lib.pb(mp(t,(ll)i));
        ll sum=0;
        for(int j=0;j<n;j++)
        {
            ll c;
            cin>>c;
            present[c].pb(i);
            adj[i].pb(c);
            sum+=score[c];
        }
        lib.insert(mp(sum,(ll)i));
        libinv.insert(mp((ll)i,sum));
        // if(i==140)
        // {
        //     for(auto it:adj[i])
        //         cout<<it<<' ';
        //     cout<<'\n';
        // }
    }
    // auto it=libinv.lower_bound(mp((ll)29998,(ll)-1));
    // if(it==libinv.end())
    // {
    //     cout<<"NO";
    // }
    cout<<l<<'\n';
    set <ll> marked;
    for(int i=0;i<l;i++)
    {
        if(lib.size()==0)
            break;
        auto it=lib.end();
        it--;
        cout<<(*it).second<<' '<<adj[(*it).second].size()<<'\n';
        vl rem;
        for(auto j:adj[(*it).second])
        {
            rem.pb(j);
            cout<<j<<' ';
        }
        cout<<'\n';
        ll got=(*it).second;
        lib.erase(it);
        auto it2=libinv.lower_bound(mp(got,(ll)-1));
        // vis[got]=1;
        assert(it2!=(libinv.end()));
        libinv.erase(it2);
        for(auto j:rem)
        {
            if(vis[j]==1)
                continue;
            vis[j]=1;
            for(auto k:present[j])
            {
                auto it3=libinv.lower_bound(mp(k,(ll)-1));
                if(it3==libinv.end())
                    continue;
                if(((*it3).first) != k)
                    continue;
                pair <ll,ll> now=(*it3);
                libinv.erase(now);
                lib.erase(mp(now.second,now.first));
                now.second=(now.second-score[j]);
                libinv.insert(now);
                lib.insert(mp(now.second,now.first));
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T=1;
    //cin>>T;
    int t=0;
    while(t++<T)
    {
        //cout<<"Case #"<<t<<":"<<' ';
        solve();
        //cout<<'\n';
    }
    cerr << "Time : " << 1000 * ((double)clock()) / (double)CLOCKS_PER_SEC << "ms\n";
}