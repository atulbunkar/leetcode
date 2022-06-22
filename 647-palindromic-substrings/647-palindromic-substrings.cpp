class Solution {
public:
    int ans;
    int countSubstrings(string s) {
        ans = s.size(); int n=s.size();
        
        vector<vector<int>> dp(n,vector<int>(n,-1));
        
        for(int i=0;i<n;i++)
            dp[i][i] = true;
        
        for(int i=0; i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(ispalin(s,i,j,dp))ans++;
            }
        }
        return ans;
    }
    
    int ispalin(string& s,int i,int j,vector<vector<int>>& dp){
        
        if(i >= j)return 1;
        if(dp[i][j]>=1)return dp[i][j];
            
        if(s[i] != s[j])return 0;
        
        else
            return dp[i][j] = ispalin(s,i+1,j-1,dp);
        
    }
};