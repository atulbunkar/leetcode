class Solution {
public:
   // int meme[][];
    int helper(vector<int> &nums,int i, int j, vector<vector<int>> &dp)
    {
        if(i > j)
            return 0;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        int l = (i==0)?1:nums[i-1];
        int r = (j==nums.size()-1)?1:nums[j+1];
        // if(i==j)
        // {
        //     return nums[i]*l*r;
        // }
        for(int k = i; k <= j; k++)
        {   
            int left = helper(nums,i,k-1,dp);
            int right = helper(nums,k+1,j,dp);
            ans = max(ans,left+(nums[k]*l*r)+right);
        }
        return dp[i][j] = ans;
    }
    
    int maxCoins(vector<int>& nums) {
        int n =nums.size();
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size(),-1));
        return helper(nums,0,n-1,dp);
        
    }
    
        
        
};