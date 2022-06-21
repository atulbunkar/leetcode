class Solution {
public:
    vector<int> dp;
    int integerBreak(int n) {
         int ans = 0 ;  dp.resize(n+1,-1);
        
        for(int i=n-1; i>0;i--){   
            ans = max(ans, dpp(n-i) * i );
        }
        return ans;
    }
    
    int dpp(int n){
        if(n==0 || n==1)return 1;
        if(n<0)return 0;
        
        if(dp[n] >-1)return dp[n];
        
        int ans = 0 ,t=1;
        
        for(int i=n; i>0 ; i--){
            ans = max(ans, dpp(n-i) * i );
            
        }
        
        return dp[n] = ans;
    }
};