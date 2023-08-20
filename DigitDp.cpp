// Let's Code, Varan!
// https://codeforces.com/problemset/problem/204/A
ll dp[20][2][11][11];

ll rec(ll i, bool tight, ll first, ll prev, string num){
    if(i==(ll)num.size()) return (first==prev);
    ll ans = 0;
    if(dp[i][tight][first][prev]!=-1) return dp[i][tight][first][prev];
    ll org = first;
    for(ll d=0; d<=9; ++d){
        if(tight && (num[i]-'0'<d)) break;
        if(first==10 && d) first = d; 
        ans += rec(i+1,(tight && (num[i]-'0')==d),first,d,num);
        first = org;
        cout<<e;
    }
    return dp[i][tight][first][prev] = ans;
}

void solve()
{
    i2(l, r);
    memset(dp, -1, sizeof(dp));
    ll ans = rec(0, true, 10, 10, to_string(r));
    memset(dp, -1, sizeof(dp));
    ans -= rec(0, true, 10, 10, to_string(l - 1));
    cout << ans << e;
}
