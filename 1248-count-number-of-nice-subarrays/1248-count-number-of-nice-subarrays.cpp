class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int ans =0, c=0;
        
        int i=0,j=0 ; int k1 = 0; int m=0;
        int n = nums.size();
        
       
        for(auto &x:nums){
            x = x%2;
        }
        
        for(i;i<n;i++){
            
            if(nums[i])k1++;
            
            if(k1>=k){
                c = 1;
                while(j<i and nums[j]==0){
                    c++; j++;
                }
                j++; k1--;
                
                m = i+1; int t =c;
                while(m<n and nums[m]==0){
                    c += t; m++;
                }
                  
                ans += c;
                
            }
            
        }
        
        
        return ans;
    }
};