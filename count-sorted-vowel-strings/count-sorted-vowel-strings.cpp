class Solution {
public:
    int countVowelStrings(int n) {
        
        int count =0;
        vector<vector<int>> dp(n+2, vector<int>(7,-1));
        
        if(n==1)return 5;
         
        return bt(n,0,1,dp); // n , vowel idx, str , dp 
     
    }
    
    int bt(int n, int idx , int str ,  vector<vector<int>>& dp ){
        
        if(str == n+1 ){
    
            return 1;
        }
        
        if(idx == 5 )return 0;
        
        if(dp[str][idx] != -1)return dp[str][idx];
            
        return dp[str][idx] = bt(n,idx, str+1,dp) + bt(n, idx+1, str , dp);
        
        
        
    }
};