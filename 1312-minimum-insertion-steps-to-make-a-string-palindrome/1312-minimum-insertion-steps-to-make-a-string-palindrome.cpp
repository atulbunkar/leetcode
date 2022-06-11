class Solution {
public:
    int ans = INT_MAX;
    int minInsertions(string s) {
        int n= s.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        return help(s,0,s.size()-1,dp);
        
    }
    
    int help(string& s, int i,int j,  vector<vector<int>>& dp){
        
        if(i>=j){
            return 0;
        }
        
        if(dp[i][j] != -1)return dp[i][j];

        
        if(s[i] == s[j]){
            return dp[i][j] = help(s,i+1,j-1,dp);
        }
        
        else {
            return dp[i][j] = 1+ min( help(s,i+1,j,dp) ,
            help(s,i,j-1,dp) ) ;
        }
        
    }
    
};