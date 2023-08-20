class Solution {
public:
    int dp[11][2][2][(1ll<<10)];
    // https://leetcode.com/problems/count-special-integers/description/

    int rec(int i, bool tight, bool isZero, int mask, string str){
        int ans = 0;
        if(i==(int)str.size()) return (!isZero);

        if(dp[i][tight][isZero][mask]!=-1) return dp[i][tight][isZero][mask];

        for(int j=0; j<=9; ++j){
            if(tight && (str[i]-'0')<j) break;
            if(!isZero && mask&(1ll<<j)) continue;

            if(!isZero || j>0) mask+=(1ll<<j);
            ans += rec(i+1,(tight && (str[i]-'0'==j)), (isZero && j==0), mask ,str);
            if(!isZero || j>0) mask-=(1ll<<j);
        }
        return dp[i][tight][isZero][mask] = ans;
    }

    int countSpecialNumbers(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,true,true,0,to_string(n));
    }
};
