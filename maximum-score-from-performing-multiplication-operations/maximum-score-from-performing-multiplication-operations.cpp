class Solution {
public:
    int maximumScore(vector<int>& nums, vector<int>& mult) {
        int n = nums.size();
        int m = mult.size();
        
        vector<vector<int>> dp( 1001,vector<int>(1001,-1) );
        
        
        if(n == 1)return nums[0]*mult[0];
        
        
        return bt(nums, mult , 0, 0 , n-1 ,dp );
        
    }
    
    int bt(vector<int>& nums, vector<int>& mult, int i, int st, int end , vector<vector<int>>& dp){
        
        if(i == mult.size() || st > end )return 0;
        
        if(dp[st][i] != -1)return dp[st][i];
        
        return dp[st][i] = max( mult[i]*nums[st] + bt(nums , mult , i+1 , st+1 , end , dp) ,   
                     mult[i]*nums[end] + bt(nums , mult , i+1 , st , end-1, dp) ) ;
        
        //dp[][] 
    }
};