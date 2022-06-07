class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();

        vector<vector<int>> dp(n, vector<int>(2,0));  //n index , 2 for buy/sell state 
        
        return dfs(p,dp,0,0);
    }
    
    int dfs(vector<int>& p, vector<vector<int>>& dp  ,int i, int buy){
        
        if(i>=p.size())
            return 0;
        
        if(dp[i][buy])return dp[i][buy];
        
        if(buy == 0){       //buy state
            return dp[i][buy] = max(dfs(p,dp,i+1,1)-p[i] , dfs(p,dp,i+1,0)); //buy or dont buy
            
        }
        
        else{               //sell state
            return dp[i][buy] = max(dfs(p,dp,i+2,0)  + p[i], dfs(p,dp,i+1,1)); //sell or dont sell
        }
        
    }
    
       
        
        
        

};