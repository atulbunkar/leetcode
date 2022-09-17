class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        
        long ans = left;
        
        for(long i= (long)left+1; i <= right;i++){
            ans = ans&i;
            if(ans==0)return 0;
        }
        
        return ans;
        
    }
};