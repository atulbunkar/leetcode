class Solution {
public:
    int ans = INT_MAX;
    int coinChange(vector<int>& coins, int amount) {
        //sort(coins.begin(), coins.end()); 
        int n = coins.size();
        
        vector<vector<int>> dp(n,vector<int>(amount+1,-1)) ;
        
        int x = dfs(0,coins,amount,0,dp);
     
        return x==INT_MAX-1 ? -1: x ;
        
    }
    
    int dfs(int i ,vector<int>& coins , int am, int t, vector<vector<int>>& dp){
        
        if(i >= coins.size() )return INT_MAX-1;
        
        if(am == 0){
            return 0;
        }
        
        if(dp[i][am] != -1)return dp[i][am];
  
        if(coins[i] > am)
            return dp[i][am] = dfs(i+1,coins,am,t,dp);
        
        else{
            return dp[i][am] = min(dfs(i,coins,am-coins[i],t+1,dp)+1 ,dfs(i+1,coins,am,t,dp) );
        }
        
        
    }
};