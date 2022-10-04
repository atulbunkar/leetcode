class Solution {
public:
    int commonFactors(int a, int b) {
        
        int ans = 0;
        for(int i=1;i<=max(a,b)/2; i++){
            
            if( a%i ==0  and b%i==0)ans++;
            
        }
        if(a==b)ans++;
        return ans;
    }
};