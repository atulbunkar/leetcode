class Solution {
public:
    bool isPowerOfFour(int n) {
        int x = 1;
        if(n==1)return true;
        
        while(n){
            if(x&n || x<<1&n)return false;
            if(n == 4)return true;
            n = n>>2;
            cout<< n;
        }
        return false;
        
    }
};