class Solution {
public:
    
    int maxx(vector<int>& ones){
        return *max_element(ones.begin(),ones.end());
    }
    
    int longestNiceSubarray(vector<int>& nums) {
        vector<int> ones(33,0);
        int check = 0;
        int i=0,j=0; int ans = 1;
        
        while(i<nums.size()){
            
            int curr = nums[i];
            
            int bit =0;
            
            while(curr>0){
                ones[bit] += (curr & 1);
                //cout<< ones[bit] << " ";
                bit++; curr >>= 1;
            }
            
            while(j<i and maxx(ones) > 1){
                int back = nums[j];
                int bit = 0;
                while(back>0){
                    ones[bit] -= (back & 1);
                    bit++; back >>= 1;
                }
                j++;
            }
            
            ans = max(ans,i-j+1);
            i++;
            
        }
        
        return ans;
        
        
        
        
        
        
    }
};