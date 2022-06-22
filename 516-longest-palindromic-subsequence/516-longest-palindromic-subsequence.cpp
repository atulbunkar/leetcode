class Solution {
public:
    
  
    int ans = 1; int mem[1001][1001];
    int longestPalindromeSubseq(string s) {
        memset(mem,-1,sizeof(mem));
        return dp(s,0,s.size()-1);
    }
    
    int dp(string& s ,int i,int j){
        
        if( j<i )return 0;
    
        if(j==i)return 1;
        
        if(mem[i][j] >-1)return mem[i][j];
        
        if(s[i] == s[j]){
            return mem[i][j] = dp(s,i+1,j-1) +2 ;   
        }
        return mem[i][j] = max(dp(s,i+1,j) , dp(s,i,j-1));

        
    }
};