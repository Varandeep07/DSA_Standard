#include<bits/stdc++.h>
using namespace std;

// https://www.codingninjas.com/codestudio/problems/unbounded-knapsack_1215029?leftPanelTab=1 

int f(int ind, int w, vector<int> &profit, vector<int> &weight, vector<vector<int>> &dp){
    if(ind==0){
        if(w<weight[0]){
            return 0;
        }
        return profit[ind]*(w/weight[0]);
    }
    if(dp[ind][w]!=-1) return dp[ind][w];
    int notTake = f(ind-1,w,profit,weight,dp);
    int Take = 0;
    if(weight[ind]<=w){
        Take = profit[ind]+f(ind,w-weight[ind],profit,weight,dp);
    }
    return dp[ind][w] = max(Take,notTake);
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(n,vector<int>(w+1,0));
    for(int i=0; i<=w; i++){
        dp[0][i] = profit[0]*(i/weight[0]);
    }
    for(int i=1; i<n; i++){
        for(int j=1; j<=w; ++j){
            int notTake = dp[i-1][j];
            int take = 0;
            if(weight[i]<=j){
                take = profit[i] + dp[i][j-weight[i]];
            }
            dp[i][j] = max(notTake,take);
        }
    }
    return dp[n-1][w];
}
