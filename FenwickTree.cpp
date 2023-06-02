#include <bits/stdc++.h>
using namespace std;
#define ll int
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
#define mll map<ll,ll>
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
 
// Let's Code 
ll n,q;
string s;
const ll N = 1e5+10;
vector<ll> fen[N];

void update(ll x, char ch){ // log n
    for(; x<=n; x+=(x&-x)){
        fen[x][ch-'a']++;
    }
}

void remove(ll x, char ch){ // log n
    for(; x<=n; x+=(x&-x)){
        fen[x][ch-'a']--;
    }
}

vector<ll> query(ll x){ // log n
    vector<ll> ans(26,0);
    for(; x>0; x-=(x&-x)){
        f(j,0,26){
            ans[j]+=fen[x][j];
        }
    }
    return ans;
}
// Problem link - https://www.hackerearth.com/practice/data-structures/advanced-data-structures/fenwick-binary-indexed-trees/practice-problems/algorithm/shil-and-palindrome-research/
void solve()
{
    cin>>n; cin>>q; cin>>s;
    f(i,0,n+1){
        f(j,0,26){
            fen[i].pb(0);
        }
    }
    f(i,1,n+1){
        update(i,s[i-1]);
    }
  
    while(q--){
        i1(x);
        if(x==1){
            i1(ind); char ch; cin>>ch;
            remove(ind,s[ind-1]);
            update(ind,ch);
            s[ind-1] = ch;
        }
        else{
            i2(a,b);
            vector<ll> varan = query(b);
            if(a!=1){
                vector<ll> t2 = query(a-1);
                f(j,0,26){
                    varan[j]-=t2[j];
                }
            }
            ll odd = 0; 
            f(j,0,26){
                odd+=(varan[j]%2);
            }
            cout<<(odd>1?"no":"yes")<<e;
        }
    }
    // for building fenwick tree -> O(logn)
    // query -> 26*log(n) + O(26)
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
