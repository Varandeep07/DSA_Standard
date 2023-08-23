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
const ll N = 2e5;
ll seg_tree[4*N+10];
ll lazy[4*N+10]; // Lazy propagation array

void build_seg_tree(ll lo, ll hi, ll node, vector<ll> &v){
    if(lo==hi){
        seg_tree[node] = v[lo];
        return;
    }
    ll mid = (lo+hi)/2;
    build_seg_tree(lo, mid, 2*node+1, v);
    build_seg_tree(mid+1, hi, 2*node+2, v);
    seg_tree[node] = seg_tree[2*node+1] + seg_tree[2*node+2];
}

// Lazy propagation update function
void update_lazy(ll node, ll lo, ll hi){
    if(lazy[node]){
        seg_tree[node] += (hi - lo + 1) * lazy[node]; // Update the node with lazy value
        
        if(lo != hi){ // If it's not a leaf node, propagate the lazy value to children
            lazy[2*node+1] += lazy[node];
            lazy[2*node+2] += lazy[node];
        }
        
        lazy[node] = 0; // Clear the lazy value for current node
    }
}

// Range update with lazy propagation
void update_range(ll curLow, ll curHigh, ll node, ll lo, ll hi, ll value){
    update_lazy(node, curLow, curHigh);
    
    if(curLow > hi || curHigh < lo) return;
    
    if(curLow >= lo && curHigh <= hi){
        seg_tree[node] += (curHigh - curLow + 1) * value;
        
        if(curLow != curHigh){ // Propagate the lazy value to children
            lazy[2*node+1] += value;
            lazy[2*node+2] += value;
        }
        
        return;
    }
    
    ll mid = (curLow + curHigh) / 2;
    update_range(curLow, mid, 2*node+1, lo, hi, value);
    update_range(mid+1, curHigh, 2*node+2, lo, hi, value);
    seg_tree[node] = seg_tree[2*node+1] + seg_tree[2*node+2];
}

ll query(ll curLow, ll curHigh, ll node, ll lo, ll hi){
    update_lazy(node, curLow, curHigh);
    
    if(lo <= curLow && hi >= curHigh){
        return seg_tree[node];
    }
    
    ll ans = 0; 
    ll mid = (curLow + curHigh) / 2;
   
    if(hi > mid){
        ans = ans + query(mid+1, curHigh, 2*node+2, lo, hi);
    }
    if(lo <= mid){
        ans = ans + query(curLow, mid, 2*node+1, lo, hi);
    }
    return ans;
}

void solve()
{
    i2(n,q);
    vi(v,n); 
    build_seg_tree(0,n-1,0,v);

    while(q--){
        i1(x);
        if(x==2){
            i1(a);
            cout << query(0, n-1, 0, a-1, a-1) << e;
        }
        else{
            i3(a, b, value);
            update_range(0, n-1, 0, a-1, b-1, value);
        }
    }
}
 
int32_t main()
{
    light

    int t = 1;
    // cin >> t;
    while (t--)
        solve();
    return 0;
}
