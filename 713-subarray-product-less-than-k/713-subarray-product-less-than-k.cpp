class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
     
        int n = nums.size();
        if(k==0)return 0;
        
        //DO USING SLIDING WINDOW : 
        // recall how to add all windows btw i to j;
        
        long long p=1; int ans =0,j=0;

        for(int i=0;i<n;i++){
            
            p *= nums[i];
            
            while(j<i and p>=k){
                p /= nums[j++];
            }
            
            if(p<k)
                ans += i-j+1;
           
        }
        
        return ans;
        
    }
};