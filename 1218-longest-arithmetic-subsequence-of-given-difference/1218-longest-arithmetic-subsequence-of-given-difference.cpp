class Solution {
public:
    int longestSubsequence(vector<int>& nums, int d) {
        int n =nums.size();
        map<int,int> dp; int ans = 1;
        
        for(int i=0;i<n;i++){
            
            dp[nums[i]] =  dp[nums[i]-d] +1 ;
            
            ans =max(ans, dp[nums[i]]);
            
        }
        
        return ans;
    }
};