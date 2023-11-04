// https://atcoder.jp/contests/dp/tasks/dp_q
#include <bits/stdc++.h> 
using namespace std; 
#define int long long
#define e endl
#define f(i,a,b) for(int i=a; i<b; ++i)
// limit for array size 
const int N = 200010; 
int tree[4 * N], dp[N]; 
int n; 
int h[N],a[N];

int query(int node, int curL, int curR, int l, int r){
    int ans = 0;
    if(curL>=l && curR<=r){
        return tree[node];
    }
    int mid = (curL+curR)/2;
    
    if(l<=mid){
        ans = query(2*node+1,curL,mid,l,r);
    }
    if(r>mid){
        ans = max(ans,query(2*node+2,mid+1,curR,l,r));
    }
    return ans;
}

void update(int node, int val){
    int par = node;
    tree[node] = val;
    if(par%2) par-=1;
    else par-=2;
    par/=2;
    while(par>=0){
        tree[par] = max(tree[2*par+1],tree[2*par+2]);
        if(par%2) par-=1;
        else par-=2;
        par/=2;
    }
}

int getNode(int node, int curLo, int curHi, int lo){
    if(curLo==lo && curHi==lo) return node;
    int mid = (curLo+curHi)/2;
    if(lo<=mid){
        return getNode(2*node+1,curLo,mid,lo);
    }
    else return getNode(2*node+2,mid+1,curHi,lo);
}

void solve()
{
    cin>>n; 
    f(i,1,n+1) cin>>h[i];
    f(i,1,n+1) cin>>a[i];
    // dp[i] -> best beauty sum ending at height i flower
    int ans = 0;
    for(int flower = 1; flower<=n; ++flower){
        int maxValue = query(0,0,N,0,h[flower]-1);
        dp[h[flower]] = max(dp[h[flower]],maxValue+a[flower]);
        ans = max(ans,dp[h[flower]]);
        update(getNode(0,0,N,h[flower]),dp[h[flower]]);
    }
    cout<<ans<<endl;
}

int32_t main() 
{ 
    int t = 1; 
    // cin>>t; 
    while(t--){
        solve();
    }
	return 0; 
} 
