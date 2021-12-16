class Solution {
public:
  //init with 0 , dp[dice][target]
    
    int numRollsToTarget(int d, int f, int t) {//d -> dice num , f -> face count
        vector<vector<vector<int>>>dp (d+2,vector<vector<int>>(f+2,vector<int>(t+2,-1)));
        
        int mod = 1000000007;
        
        //cout << dp[5][5][33];
        return bt(t,d,f , f ,dp) % mod ;
    }
    
    int bt(int t, int curD, int curF ,int f ,vector<vector<vector<int>>>& dp){
        
        if(curD == 0 and t==0){
            return 1;
        }
        if(t < 0 || curF <= 0 || curD < 0)return 0;
        
        if(dp[curD][curF][t] != -1)return dp[curD][curF][t] ;  
        
        int mod = 1000000007;
        if(curF <= t){
            return dp[curD][curF][t] = bt( t-curF , curD-1 , f,f , dp) % mod + bt(t , curD ,curF-1 ,f ,dp) %mod ;  
        }
        
        return dp[curD][curF][t] = bt(t , curD ,curF-1 ,f,dp) %mod  ;
        
    }
    
    
};