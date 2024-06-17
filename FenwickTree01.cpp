// https://leetcode.com/problems/peaks-in-array/
// Fenwikc tree Bit[i] = storing answer for j to i (j formed after removing last set bit of i index) 
// i&-i ---> gives last set bit of i

class Solution {
public:
    // Let's Code Varan!
    // Bit[i] -> elements j to i (j -> element formed after removing last bit of i)
    // Bit[12] -> 1100 -> ans for range (9 - 12)
    vector<int> Bit;

    void upd(int idx, int val, int &n){
        for( ;idx<=n; idx += (idx&-idx)){
            Bit[idx] += val;
        }
    }

    int Count(int idx){
        int ans = 0; 
        for(; idx>0; idx-=(idx&-idx)){
            ans += Bit[idx];
        }
        return ans;
    }

    bool isPeak(int idx, vector<int> &nums, int n){
        if(idx==1 || idx==n) return false;
        return nums[idx-1]>nums[idx-2] && nums[idx-1]>nums[idx];
    }

    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        Bit = vector<int> (n+1,0);
        vector<int> ans;
        for(int i=1; i<=n; ++i){
            if(isPeak(i,nums,n)){
                upd(i,1,n);
            }
        }
        for(auto &x: queries){
            if(x[0]==1){
                x[1]++; x[2]++;
                if(x[1]==x[2]){
                    ans.push_back(0); continue;
                }
                int value = Count(x[2])-Count(x[1]-1);
                value -= isPeak(x[1],nums,n);
                value -= isPeak(x[2],nums,n);
                ans.push_back(value);
            }
            else{
                bool prevP, nowPeak;
                int j = x[1];
                if(j>0 && j<n-1){
                    prevP = isPeak(j+1,nums,n);
                    nowPeak = x[2]>nums[j-1] && x[2]>nums[j+1];
                    if(prevP!=nowPeak) upd(j+1,(nowPeak?1:-1),n);
                }
                if(j-2>=0){
                    prevP = isPeak(j,nums,n);
                    nowPeak = nums[j-1]>nums[j-2] && nums[j-1]>x[2];
                    if(prevP!=nowPeak) upd(j,(nowPeak?1:-1),n);
                }
                if(j+2<n){
                    prevP = isPeak(j+2,nums,n);
                    nowPeak = nums[j+1]>nums[j+2] && nums[j+1]>x[2];
                    if(prevP!=nowPeak) upd(j+2,(nowPeak?1:-1),n);
                }
                nums[x[1]] = x[2];
            }
        }
        return ans; 
    }
    
};
