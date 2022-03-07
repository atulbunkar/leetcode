class Solution {
public:
    uint32_t reverseBits(uint32_t n){
        uint32_t b=0;
        
        for(int i=31; i >=0; i--){
            
            if(1<<i&n){
                int j = 31-i;
                b = b | (1<<j) ;
            }
            
        }
        return b;
    }
};