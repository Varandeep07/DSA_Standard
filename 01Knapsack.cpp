#include <bits/stdc++.h> //https://www.interviewbit.com/problems/0-1-knapsack/
using namespace std;  

int f(int ind, vector<int> &A, vector<int> &B, int W, vector<vector<int>> &dp){

    if(ind<0 || W<=0) return 0;

    if(dp[ind][W]!=-1){
        return dp[ind][W];
    }

    int notTake = f(ind-1,A,B,W,dp);
    int Take = INT_MIN;

    if(B[ind]<=W){
        Take = f(ind-1,A,B,W-B[ind],dp)+A[ind];
    }

    return dp[ind][W] = max(Take,notTake);
}

int solve(vector<int> &A, vector<int> &B, int C) {

    int n = A.size();
    vector<vector<int>> dp(n+1,vector<int>(C+1,0));

    for(int i=1; i<=C; i++){
        dp[0][i] = 0;
    }
    for(int i=0; i<=n; i++){
        dp[i][0] = 0;
    }

    for(int i=1; i<=n; i++){
        for(int j=1; j<=C; j++){
            dp[i][j] = dp[i-1][j];
            if(B[i-1]<=j){
                dp[i][j] = max(dp[i][j],A[i-1]+dp[i-1][j-B[i-1]]);
            }
        }
    }

    return dp[n][C];  // dp[i][j] is the maximum profit you get by taking or not taking ith element in Knapsack of size j
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> val(n),wt(n); int capacity;
        for (int i = 0; i < n; ++i)
        {
            cin>>val[i];
        }
        for (int i = 0; i < n; ++i)
        {
            cin>>wt[i];
        }
        cin>>capacity;
        cout<<solve(val,wt,capacity);
    }
}