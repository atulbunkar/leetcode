class Solution {
public:
    int minSteps(int n) {
        vector<vector<int>> dp(n+1, vector<int>(2,-1));
        if(n==1)return 0;
        
        return dpp(1,1,n,1,dp) +1;
        
    }
    int dpp(int i,int len , int n, int copy ,vector<vector<int>>& dp){
        if(i>n || len>n)return INT_MAX-1000;
        
        if(i==n)return 0;
        
        //if(dp[i][copy] >-1)return dp[i][copy];
        
        if(copy){
             return dp[i][copy]  = dpp(i+len,len,n,0,dp)+1;
        }
        
        return dp[i][copy] = min( dpp(i+len,len,n,0,dp) , dpp(i,i,n,1,dp)  ) +1  ;
    }
    
};