class Solution {
public:
    bool isUgly(int n) {
        if(n<=0)return false;
        
        return gcd(n);
    }
     bool gcd(int i){
        if(i==1)return true;
        
        if(i%2==0)return gcd(i/2);
        else if(i%3==0)return  gcd(i/3);
        else if(i%5==0)return  gcd(i/5);
        
        return  false;
    }
};