#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define e '\n'
#define f(i, a, b) for (ll i = a; i < b; i++)
#define vll vector<ll>
#define all(v) v.begin(),v.end()
#define pb push_back
#define i1(a) \
    ll a;    \
    cin >> a;
#define i2(a, b) \
    ll a, b;    \
    cin >> a >> b;
#define i3(a, b, c) \
    ll a, b, c;    \
    cin >> a >> b >> c;  
#define is(str) \
    string str; \
    cin>>str;
#define vi(arr, n)    \
    vector<ll> arr(n); \
    f(i, 0, n) cin >> arr[i];
#define printv(arr,n) \
    f(i,0,n) cout<<arr[i]<<' ';
#define mod 1000000007
#define ff first
#define ss second
#define R return
#define light ios_base::sync_with_stdio(false); \
        cin.tie(NULL); 
#define B break
#define C continue
#define YY cout << "YES" << e
#define NN cout << "NO" << e
// #pragma GCC optimize ("trapv")

ll Powerfun(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1) res = (res * x) % mod;
        x = (x * x) % mod; y >>= 1;
    }
    return res;
}

ll add(ll a, ll b){
    return (a%mod+b%mod)%mod;
}

ll sub(ll a, ll b){
    return (a%mod-b%mod+mod)%mod;
}

ll mul(ll a, ll b){
    return ((a%mod)*(b%mod))%mod;
}
 
// Let's Code, Varan! 
ll up[200001][21];
vll level;
// https://cses.fi/problemset/task/1135/
void binaryLift(ll node, ll par, ll lvl, vll G[]){
    up[node][0] = par;
    level[node] = lvl;
    for(ll i=1; i<21; ++i){
        if(up[node][i-1]==-1) break;
        up[node][i] = up[up[node][i-1]][i-1];
    }

    for(auto &x: G[node]){
        if(x==par) continue;
        binaryLift(x,node,lvl+1,G);
    }
}

ll lift_up(ll node, ll level){
  
    for(ll i=0; i<21; ++i){
        if((1ll<<i)&level){
            node = up[node][i];
            if(node==-1) break;
        }
    }
    return node;
}

void solve()
{
    i2(n,q);
    vll G[n+1];
    f(i,1,n){
        i2(a,b);
        G[a].pb(b); G[b].pb(a);
    } 
    memset(up,-1,sizeof(up));
    level = vll(n+1,0);

    binaryLift(1,-1,1,G);
    
    while(q--){
        i2(a,b);
        
        if(level[a]<level[b]){
            swap(a,b);
        }
    
        ll dist = level[a]-level[b];
        a = lift_up(a,level[a]-level[b]);
        
        ll org = a;
       
        if(a==b){
            cout<<dist<<e; continue;
        }
    
        for(ll i=20; i>=0; --i){
            if(up[a][i]!=up[b][i]){
                a = up[a][i];
                b = up[b][i];
            }
        }
        a = lift_up(a,1);
        dist += 2*(level[org]-level[a]);
        cout<<dist<<e;
    }
    cout<<e;
}
 
int32_t main()
{
    light

    int t = 1;
    // cin>>t;
    while (t--)
        solve();
    return 0;
}
