class Solution {
public:
    int ans;
    int countSubstrings(string s) {
        ans = s.size(); int n=s.size();
        
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        
        for(int i=0;i<n;i++)
            dp[i][i] = true;
        
        for(int i=0; i<n;i++){
            for(int j=i+1;j<n;j++){
                if(ispalin(s,i,j,dp))ans++;
            }
        }
        return ans;
    }
    
    bool ispalin(string& s,int i,int j,vector<vector<bool>>& dp){
        
        //if(dp[i][j-1] and s[j]==s[i])return dp[i][j] = true;
            
        int x = i , y = j;
        while(i<j){
            if(s[i++] != s[j--])return false;
        }
        return true ; //dp[x][y] = true;
        
    }
};