// Problem -> https://www.codechef.com/problems/TREEDISTSET
// Sol -> Find the diameter path and assign colors like this RRR...BBB
// 1. pick any random node and find its farthest node say d1
// 2. from d1, find its farthest node say d2
// d1 ----- d2 are two end points of the diameter

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define f(i, a, b) for (ll i = a; i < b; i++)
#define vll vector<ll>
#define all(v) v.begin(), v.end()
#define pb push_back
#define i1(a) \
    ll a;     \
    cin >> a;
#define i2(a, b) \
    ll a, b;     \
    cin >> a >> b;
#define i3(a, b, c) \
    ll a, b, c;     \
    cin >> a >> b >> c;
#define is(str) \
    string str; \
    cin >> str;
#define vi(arr, n)     \
    vector<ll> arr(n); \
    f(i, 0, n) cin >> arr[i];
#define printv(arr, n) \
    f(i, 0, n) cout << arr[i] << ' ';
#define mod 1000000007
#define ff first
#define ss second
#define mll map<ll, ll>
#define R return
#define light                         \
    ios_base::sync_with_stdio(false); \
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
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
// use st.order_of_key(int), st.find_by_order(1) -> iterator to second smallest element, less_equal makes it multiset

ll Powerfun(ll x, ll y)
{
    ll res = 1;
    while (y)
    {
        if (y & 1)
            res = (res * x) % mod;
        x = (x * x) % mod;
        y >>= 1;
    }
    return res;
}

ll add(ll a, ll b)
{
    return (a % mod + b % mod) % mod;
}

ll sub(ll a, ll b)
{
    return (a % mod - b % mod + mod) % mod;
}

ll mul(ll a, ll b)
{
    return ((a % mod) * (b % mod)) % mod;
}

// Let's Code Varan!
ll n;
vll diamArr;
ll root, d1, d2;
vll G[2010];

void dfs1(ll node, ll par, ll curD, ll &maxD, bool ok){

    if(maxD<curD){
        if(ok) d1 = node;
        else d2 = node;
        maxD = curD;
    }

    for(auto &child: G[node]){
        if(child==par) continue;
        dfs1(child,node,curD+1,maxD,ok);
    }
}

void dfs2(ll curN, ll par, ll endN, vector<ll> &values){
    values.push_back(curN);
    if(curN==endN){
        diamArr = values;
        return;
    }
    for(auto &child: G[curN]){
        if(child==par) continue;

        if(diamArr.size()) break;

        dfs2(child,curN,endN,values);
    }
    values.pop_back();
}

void solve()
{
    f(i,0,n+5) G[i].clear();
    diamArr.clear();
    root = 0; d1 = 0, d2 = 0;

    cin>>n;
    f(i,1,n){
        i2(a,b); 
        if(root==0) root = a;
        G[a].pb(b); G[b].pb(a);
    }
    ll maxD=0;
    dfs1(root,-1,0,maxD,true);
    maxD = 0;
    dfs1(d1,-1,0,maxD,false);
    vll values;
    dfs2(d1,-1,d2,values);

    vll color(n+1,0);
    ll szDiamArr = diamArr.size();
    ll cntR = szDiamArr/2, cntB = szDiamArr-cntR;
    // 1 -> R , 2 -> B
    for(auto &x: diamArr){
        if(cntR){
            color[x] = 1; cntR--;
        }
        else color[x] = 2; 
    } 
    cntR = szDiamArr/2;
    f(i,1,n+1){
        if(color[i]==0){
            if(cntR>cntB){
                color[i] = 2; cntB++;
            }
            else color[i] = 1, cntR++;
        }
        if(color[i]==1) cout<<"R";
        else cout<<"B";
    }
    cout<<endl;
}

int32_t main()
{
    light

    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}
