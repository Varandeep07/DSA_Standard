// Let's Code, Varan! 
// https://cses.fi/problemset/task/1687/

void binaryLifting(ll node, ll par, vector<vll> &dp, vll G[]){
    
    dp[node][0] = par;

    for(ll i=1; i<30; ++i){
        ll value = dp[node][i-1];
        if(value==-1) break;
        dp[node][i] = dp[value][i-1];
    }

    for(auto &child: G[node]){
        if(child==par) continue;
        binaryLifting(child,node,dp,G);
    }
}

void solve()
{
    i2(n,q);
    vll G[n+1];
    f(i,2,n+1){
        i1(x);
        G[i].pb(x); G[x].pb(i);
    }

    vector<vector<ll>> dp(n+1,vector<ll>(32,-1));
    binaryLifting(1,-1,dp,G);
     
    while(q--){
        i2(node,level);
        ll ans = -1;
        for(ll i=0; i<30; ++i){
            if((1ll<<i)&level){
                node = dp[node][i];
                if(node==-1) break;
            }
        }
        cout<<node<<" ";
    }
    cout<<e;
}
