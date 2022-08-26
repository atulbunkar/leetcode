class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        // atmost k-1;
        k--;
        
        int n = nums.size();
        
        int ans = 0;
        long p = 1 ,j=0;
        
        for(int i=0;i<n;i++){
            
            p *= nums[i];
            
            while(j<i and p>k){
                p /= nums[j++];
            }
            
            if(p<=k)ans+= i-j+1 ;
            
        }

        
        return ans;
        
    }
};