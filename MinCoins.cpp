int f(int ind, int x, vector<int> &num, vector<vector<int>> &dp){
    if(ind==0){
        if(x%num[ind]) return INT_MAX;
        return x/num[ind];
    }
    if(dp[ind][x]!=-1){
        return dp[ind][x];
    }
    int notTake = f(ind-1,x,num,dp);
    int Take = INT_MAX;
    if(num[ind]<=x){
        int val = f(ind,x-num[ind],num,dp);
        if(val!=INT_MAX)
            Take = 1+val;
    }
    return dp[ind][x] = min(Take,notTake);
}
int minimumElements(vector<int> &num, int x)
{
    int n = num.size();
    vector<vector<int>> dp(n,vector<int>(x+1,1e9));
    for(int i=0; i<=x; i++){
        if(i%num[0]==0) dp[0][i] = i/num[0];
        else dp[0][i] = 1e9;
    }
    for(int i=1; i<n; i++){
        for(int j=0; j<=x; j++){
            int notTake = dp[i-1][j];
            int Take = 1e9;
            if(num[i]<=j){
                Take = 1+dp[i][j-num[i]];
            }
            dp[i][j] = min(Take,notTake);
        }
    }
    if(dp[n-1][x]==1e9) return -1;
    return dp[n-1][x];
}