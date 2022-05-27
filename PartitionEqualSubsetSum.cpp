#include <bits/stdc++.h>
using namespace std;

bool f(int ind, int target, vector<int> &arr){
    if(target==0) return true;
    if(ind==0) return (arr[ind]==target);
    bool notTake = f(ind-1,target,arr);
    bool take = false;
    if(arr[ind]<=target){
        take = f(ind-1,target-arr[ind],arr);
    }
    return take|notTake;
}
bool canPartition(vector<int> &arr, int n)
{
    int sum = 0;
    for(int i=0; i<n; i++) sum+=arr[i];
    if(sum%2) return false;
    sum/=2;
    vector<vector<bool>> dp(n,vector<bool>(sum+1,false));
    for(int i=0; i<n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++){
            dp[i][j] = dp[i-1][j];
            if(arr[i]<=j){
                dp[i][j] = dp[i][j] | dp[i-1][j-arr[i]];
            }
        }
    }
    return dp[n-1][sum];
}

int main(){
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif

    int t; cin>>t;
    while(t--){
        int n; cin>>n;
        vector<int> arr(n);
        for (int i = 0; i < n; ++i)
        {
            cin>>arr[i];
        }
        cout<<canPartition(arr,n)<<endl;
    }
}