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
// link - https://codeforces.com/contest/1873/problem/H
vll cycleP;

void dfs(ll i, ll par, vll G[], vector<ll> &path, vector<bool> &curVis){
    if((ll)cycleP.size()) return;
    path.push_back(i);
    curVis[i] = true;
    
    for(auto &child: G[i]){
        if(child==par) continue;
        if(cycleP.size()) return;
        if(curVis[child]){
            for(int j=path.size()-1; j>=0; --j){
                cycleP.push_back(path[j]);
                if(path[j]==child) break;
            }
            return;
        }
        dfs(child,i,G,path,curVis);
    }

    curVis[i] = false;
    path.pop_back();
}

pair<ll,ll> bfs(ll st, vll &CycleP, vll G[]){
    ll dist = 0, pointToreturn = 0;

    queue<ll> que;
    set<ll> cycleset,vis;
    for(auto &x: CycleP){
        cycleset.insert(x);
    }

    que.push(st);
    vis.insert(st);

    while(que.size()){
        ll sz = que.size();
        
        while(sz--){
            ll node = que.front(); que.pop();
            if(cycleset.find(node)!=cycleset.end()){
                pointToreturn = node;
                break;
            }
            for(auto &x: G[node]){
                if(vis.find(x)==vis.end()){
                    vis.insert(x);
                    que.push(x);
                }
            }
        }
        if(pointToreturn) break;
        dist++;
    }
    return {dist,pointToreturn};
}

void solve()
{
    i3(n,a,b);
    vll G[n+1];
    cycleP.clear();
    f(i,0,n){
        i2(x,y); G[x].pb(y); G[y].pb(x);
    }
    if(a==b){
        NN; R;
    }
    
    vector<bool> curVis(n+10,false);
    vector<ll> path;
    dfs(1,-1,G,path,curVis);

    for(auto &x: cycleP){
        if(x==b){ YY; R; }
    }
    // calc min distance of thief from cycle using bfs
    pair<ll,ll> thief = bfs(b,cycleP,G);
    vll pointv = {thief.second};

    pair<ll,ll> Cop = bfs(a,pointv,G);
  
    if(thief.ff<Cop.ff) YY;
    else NN;
}
 
int32_t main()
{
    light

    int t = 1;
    cin>>t;
    while (t--)
        solve();
    return 0;
}
