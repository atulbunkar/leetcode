class Solution {
public:
    int mem[101][101];   const int inf = 1e7; int memo[101][101];

    int palindromePartition(string s, int k) {
         memset(mem,-1,sizeof(mem)); memset(memo,-1,sizeof(memo));
        int n=s.size();
        
        return dp(s,0,k-1);
    }
    
    int dp(string&s , int i,int k){
        
        if(k==0)return tochange(s,i,s.size()-1);  
        if(i == s.size()) return inf;
        
        if(memo[i][k] != -1)return memo[i][k];
        int tmp = inf;
        
        for(int j=i; j<s.size()-1 ;j++){
            tmp = min(tmp, ( tochange(s,i,j) +dp(s,j+1,k-1) ) );      
        }
        return memo[i][k] = tmp;
    }
    
    
     int tochange(string& s, int i,int j){ //after a few calls , our mem table is full to use
        if(j<=i)return 0;
        
        if(mem[i][j] != -1)return mem[i][j] ;
         
        if(s[i]==s[j])return mem[i][j] = tochange(s,i+1,j-1);
         
         return mem[i][j] = 1+ tochange(s,i+1,j-1);
    }
};