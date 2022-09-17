class Solution {
public:
    int largestCombination(vector<int>& c) {
        vector<int> bits(32,0);
        
        for(auto x:c){
            int bit = 0;
            while(x>0){
                if(x&1)bits[bit]++;
                bit++;
                x >>= 1;
            }
            
        }
        return *max_element(bits.begin(),bits.end());
    }
};