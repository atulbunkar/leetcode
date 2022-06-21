class Solution {
public:
    
    int numSquares(int n) {
        vector<int> mem;
        mem.resize(n+1,-1);
        return dp(n,mem);
    }
    
    int dp(int n , vector<int>& mem){
        int ans = INT_MAX;
        if(n<0)return INT_MAX ;
        
        if(mem[n] >-1)return mem[n];
        if(n==0)return mem[0] = 0;
        
        float sq;
        
        for(int i=1 ; i*i <=n; i++){
            
            ans = min(ans , 1 + dp(n-i*i,mem) );
            
        }
        
        return mem[n] = ans;
    }
};