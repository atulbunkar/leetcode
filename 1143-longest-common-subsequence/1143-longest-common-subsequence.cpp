class Solution {
public:
    string t1,t2; int mem[1001][1001] ;
    
    int longestCommonSubsequence(string text1, string text2) {
        t1 = text1; t2 = text2;
        memset(mem,-1,sizeof(mem));
        
        return dp(t1.size()-1, t2.size()-1);
    }
    
    int dp(int i,int j){
        if(i<0|| j<0)return 0;
        if(mem[i][j] >-1)return mem[i][j];
        
        if(t1[i]==t2[j])return mem[i][j] = dp(i-1,j-1)+1;
        
        else return mem[i][j] =max(dp(i-1,j) , dp(i,j-1));
        
    }
};