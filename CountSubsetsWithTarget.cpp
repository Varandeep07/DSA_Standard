#include <bits/stdc++.h>
using namespace std;

int findWays(vector<int> &num, int tar)
{
    int n = num.size();
    vector<int> prev(tar+1,0), curr(tar+1,0);
    prev[0] = 1; 
    if(num[0]<=tar) prev[num[0]] = 1; 
    curr[0] = 1;
    for(int i=1; i<n; i++){
        for(int j=1; j<=tar; j++){
            curr[j] = prev[j];
            if(j-num[i]>=0){
                curr[j] += prev[j-num[i]];
            }
        }
        prev = curr;
    }
    return prev[tar];
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
        for(int i=0; i<n; i++) cin>>arr[i];
        cout<<findWays(arr,target)<<endl;
    }
}