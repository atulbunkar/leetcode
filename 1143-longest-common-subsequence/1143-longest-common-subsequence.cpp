class Solution {
public:
    string t1,t2; 
    
    int longestCommonSubsequence(string text1, string text2) {
        t1 = text1; t2 = text2;
         int n= t1.size(), m = t2.size();
        
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        
        for(int i=0; i<n;i++){
            if(t2[0] == t1[i])
                dp[i][0] = 1;
            else
                dp[i][0] = (i==0) ? 0: dp[i-1][0];
        }
        
        for(int i=0;i<m;i++){
            if(t1[0] == t2[i])
                dp[0][i] =1;
            else
                dp[0][i] = i==0 ?0 :dp[0][i-1];
        }
        
        for(int i=1;i<n;i++){
            for(int j=1; j<m;j++){
                
                
                if(t1[i] == t2[j])
                    dp[i][j] = dp[i-1][j-1]+1;
                else
                    dp[i][j] = max( dp[i-1][j] ,dp[i][j-1]);
                
            }
        }
        
        
        return dp[n-1][m-1];
   
    }
    
//     int dp(int i,int j){         //top down
//         if(i<0|| j<0)return 0;
//         if(mem[i][j] >-1)return mem[i][j];
        
//         if(t1[i]==t2[j])return mem[i][j] = dp(i-1,j-1)+1;
        
//         else return mem[i][j] =max(dp(i-1,j) , dp(i,j-1));
        
//     }
};