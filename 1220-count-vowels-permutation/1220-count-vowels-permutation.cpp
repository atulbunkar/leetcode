class Solution {
public:
     int mod = 1e9+7;
     long mem[20001][8];
    
    int countVowelPermutation(int n) {
        memset(mem,-1,sizeof(mem));
        return dp(n,-1);
    }
    
    int dp(int n , int prev){
        
        if(n==0)return 1;
        
        if(mem[n][prev+1] !=-1)return mem[n][prev+1];
        
        if(prev==0)return mem[n][prev+1] =  dp(n-1,1)%mod;
        if(prev==1)return mem[n][prev+1] = dp(n-1,0)%mod + dp(n-1,2)%mod;
        
        if(prev==3)return mem[n][prev+1] = dp(n-1,2)%mod + dp(n-1,4)%mod;
        if(prev==4)return mem[n][prev+1] = dp(n-1,0)%mod;
        
        long ans = 0;
        for(int i=0; i<5 ;i++){
            if(prev == 2 and i==2)continue;
            ans += dp(n-1,i)%mod ;
            ans = ans %mod ;
        }
        return mem[n][prev+1] = ans;
        
        
        
    }
};