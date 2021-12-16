class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        if (amount == 0) return 1;
        int n = coins.size();
        
        vector<vector<int>> memo(n+1, vector<int>(amount+1,0));
        memo[0][0] =1;  //1 way to get amount =0;
        
        for(int i = 1; i <= n ; i++){
            memo[i][0] = 1;         //IMP - set this to 1. which will be added to later cases. 
                                     //1 way to get 0 sum.
            
            for(int am = 1; am <= amount; am++){
                
                memo[i][am] = memo[i-1][am];
                
                if(am-coins[i-1] >= 0){
                    memo[i][am] = memo[i-1][am] + memo[i][am-coins[i-1]];
                }
            
            }   
        }
       return memo[n][amount]; 
    }
    
  
};