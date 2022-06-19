class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(n+1,-1));
        if(n==1)return 0;
        
        return dpp(1,1,n,1,dp) +1;
        
    }
    int dpp(int i,int len , int n, int copy ,vector<vector<int>>& dp){
        if(i>n || len>n)return INT_MAX-1000;
        
        if(i==n)return 0;
        
        if(dp[i][len] >-1)return dp[i][len];
        
        if(copy){
             return dp[i][len]  = dpp(i+len,len,n,0,dp)+1;
        }
        
        return dp[i][len] = min( dpp(i+len,len,n,0,dp) , dpp(i,i,n,1,dp)  ) +1  ;
    }
    
};