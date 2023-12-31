#include <bits/stdc++.h>
using namespace std;
#define ll int
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
#define mll map<ll,ll>
#define R return
#define light ios_base::sync_with_stdio(false); \
        cin.tie(NULL); 
#define B break
#define C continue
#define YY cout << "YES" << endl
#define NN cout << "NO" << endl
// #pragma GCC optimize ("trapv")
 
// PBDS starts --
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// use st.order_of_key(int), st.find_by_order(1) -> iterator to second smallest element 
 
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
 
// Let's Code Varan!
// https://cses.fi/problemset/task/1669/
ll n,m; 
vector<ll> path;
vector<bool> gv;
bool STOP = false;

void rec(ll node, ll par, stack<ll> &st, vector<bool> &vis, vll G[]){
    st.push(node);

    if(STOP) return; // 1

    vis[node] = true; 
    gv[node] = true;

    for(auto &child: G[node]){
        if(STOP) return; // 2

        if(vis[child]){
            if(child==par) continue;
            path.pb(child);
            while(!st.empty() && st.top()!=child){
                path.pb(st.top());
                st.pop();
            }
            path.pb(child);
            STOP = true;
            return;
        }
        if(STOP) return; // 3

        rec(child,node,st,vis,G);
    }

    if(STOP) return; // 4 

    st.pop();
    vis[node] = false;
}

void solve()
{
    cin>>n>>m;
    vll G[n+1];
    gv = vector<bool>(n+1,false);
    f(i,0,m){
        i2(a,b);
        G[a].pb(b);
        G[b].pb(a);
    }
    f(i,1,n+1){
        if(!gv[i] && path.size()==0){
            vector<bool> vis(n+1,false);
            stack<ll> st;
            rec(i,-1,st,vis,G);
        }
    }
    if(path.size()==0){
        cout<<"IMPOSSIBLE"<<endl;
        return;
    }
    cout<<path.size()<<endl;
    for(auto &x: path){
        cout<<x<<" ";
    }
    cout<<endl;
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
