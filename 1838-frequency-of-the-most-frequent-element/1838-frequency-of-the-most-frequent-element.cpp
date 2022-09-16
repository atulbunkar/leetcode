class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size(), i=0,j=0;
        long sum = 0; int ans =0;
        sort(nums.begin(),nums.end());
        
        while(i<n){
            sum += nums[i];
            
            while( (long)nums[i]*(i-j+1) > sum+k)sum -= nums[j++];
            
            ans = max(ans, i-j+1);
            i++;
            
        }
        return ans;
    }
};