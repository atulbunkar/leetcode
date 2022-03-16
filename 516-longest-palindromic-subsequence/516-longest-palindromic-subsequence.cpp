class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n,vector<int>(n)); 
        int l = 0 ,r = n-1;
        
        return bt(l,r,dp , s);
        
    }
    
    int bt(int l, int r, vector<vector<int>>& dp , string& s){
        
        if(l==r)return 1;
        if(l>r)return 0;
        
        if(dp[l][r])return dp[l][r];
        
        if(s[l]==s[r]){
            return dp[l][r] = 2 + bt(l+1,r-1,dp,s);
        }
        
            
        return dp[l][r] = max( bt(l,r-1,dp,s), bt(l+1,r,dp,s) );
     
        
        
    }
};