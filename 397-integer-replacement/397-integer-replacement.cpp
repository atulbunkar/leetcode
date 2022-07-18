class Solution {
public:
    unordered_map<int,int> mem;
    int integerReplacement(int n) {
      if(n==INT_MAX)return 32;
        
         return dp(n);
    }
    int dp(int i){
        if(i==1)return 0;
        
        if(mem[i]>0)return mem[i];
        
        if(i%2==0)return mem[i]= 1+dp(i/2);
        else
            return mem[i] = min(dp(i+1) , dp(i-1)) +1;
    }
};