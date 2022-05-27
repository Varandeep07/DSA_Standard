#include <bits/stdc++.h>
using namespace std;


bool f(int ind, int target, vector<int> &arr,vector<vector<int>> &dp){
    if(target==0){
        return true;
    }
    if(ind==0){
        return arr[ind]==target;
    }
    if(dp[ind][target]!=-1){
        return dp[ind][target];
    }
    bool take = false;
    if(target>=arr[ind]){
        take = f(ind-1,target-arr[ind],arr,dp);
    }
    bool ntake = f(ind-1,target,arr,dp);
    return dp[ind][target] = take|ntake;
} 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int i=1; i<n; i++){
        for(int j=1; j<=k; j++){
            dp[i][j] = dp[i-1][j];
            if(j-arr[i]>=0){
                dp[i][j] = dp[i][j] | dp[i-1][j-arr[i]];
            }
        }
    }
    return dp[n-1][k];
}

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin>>t;
    while(t--){
        int n,target; cin>>n>>target;
        vector<int> arr(n);
        for(int i=0; i<n; i++){
            cin>>arr[i];
        }
        cout<<subsetSumToK(n,target,arr)<<endl;
    }
}