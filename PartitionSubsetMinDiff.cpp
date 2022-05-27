 #include <bits/stdc++.h>
using namespace std;

int minSubsetSumDifference(vector<int>& arr, int n)
{
    int sum = 0;
    for(int i=0; i<n; i++) sum+=arr[i];
    int Tsum = sum;
    sum = (sum/2)+1;
    vector<bool> prev(sum+1,false);
    vector<bool> curr(sum+1,false);
    prev[0] = true, prev[arr[0]] = true, curr[0] = true;
    int ans = Tsum;
    for(int i=1; i<n; i++){
        for(int j=1; j<=sum; j++){
            curr[j] = prev[j];
            if(j-arr[i]>=0){
                curr[j] = curr[j]|prev[j-arr[i]];
            }
        }
        prev = curr;
    }
    for(int i=0; i<=sum; i++)
        if(prev[i])
            ans = min(ans,abs(i-(Tsum-i)));
    return ans;
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
		for(int i=0; i<n; i++) cin>>arr[i];
		cout<<minSubsetSumDifference(arr,n)<<endl;
	}
}
