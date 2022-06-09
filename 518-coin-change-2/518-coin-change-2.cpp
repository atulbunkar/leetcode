class Solution {        // UNBOUNDED KNAPSACK
public:
    int ans = 0;
    int change(int amount, vector<int>& coins) {
        
        if (amount == 0) return 1;
        int n = coins.size();
        
        vector<vector<int>> memo(n, vector<int>(amount+1,-1));
        
        return dfs(0,amount,coins,memo);
    }
    
    int dfs(int i ,int amount, vector<int>& coins ,  vector<vector<int>>& memo){
  
        if(amount < 0 || i >= coins.size())return 0;
        
        if(amount == 0){
            return 1;
        }
        
        if(memo[i][amount] != -1)return memo[i][amount];
        
        return memo[i][amount] = dfs(i,amount-coins[i] , coins,memo) + dfs(i+1,amount , coins,memo);
         
    }
    
  
};