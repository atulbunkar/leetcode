class Solution {
public:
    
    int mem[201][201];
    
    int getMoneyAmount(int n) {
        memset(mem,-1,sizeof(mem));
        return dp(1,n);
    }
    
    int dp(int i, int n){
        
        if(i>=n)return 0;
        int minn= INT_MAX;
        
        if(mem[i][n]!=-1)return mem[i][n];
        
        for(int k=i; k<=n; k++){
            
            minn = min( minn, max(dp(i,k-1), dp(k+1,n)) + k );
        } 
        
        return mem[i][n] = minn;
    }
};