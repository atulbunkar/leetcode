class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = accumulate(nums.begin(),nums.end(),0);
        int min0 = 0,res = 1e7; int j=0;
        
        for(int i=0;i<2*n;i++){
            
            if(nums[i%n] == 0)min0++;
            
            if(i<one)continue;
            
            if(nums[j++%n]==0)min0--;
            
            res = min(res,min0);
            
        }
        
        return res;
    }
};