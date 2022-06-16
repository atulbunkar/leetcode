class Solution {
public:             
    int ans = INT_MAX;
    int coinChange(vector<int>& coins, int am) {
        sort(coins.begin(), coins.end()); 
        int n = coins.size();
        
        vector<vector<int>> dp(n+1,vector<int>(am+1,0)); //row - arr , col - amount
        
        for(int i=0;i<=n;i++)
            dp[i][0] = 0;
        
        for(int i=0; i<=am;i++)
            dp[0][i] = INT_MAX-1;
        
        dp[0][0] = INT_MAX-1;
   
        for(int a=1;a<=am;a++){
            if(a%coins[0]==0)dp[1][a] = a/coins[0];
            else
                dp[1][a] = INT_MAX-1;
        }
     
        for(int i=2;i <=n;i++){
            for(int j=1 ;j<= am;j++){
             
                if(coins[i-1] <= j){
                    dp[i][j] = min(dp[i-1][j] , dp[i][j-coins[i-1]]+1);
                }
                else
                    dp[i][j] = dp[i-1][j];
                
            }
        }
        
        return dp[n][am] == INT_MAX-1 ? -1 : dp[n][am];
    }
};