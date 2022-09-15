class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        int i = 1, j = n-2;
        sort(nums.begin(),nums.end());
        int b = 2,aa=2;
        
        if(n<=4)return 0;
        
        int diff = nums[n-1] - nums[0];
        
        diff = min(diff, nums[n-4]-nums[0]);
         diff = min(diff, nums[n-1]-nums[3]);
        
         diff = min(diff, nums[n-2]-nums[2]);
         diff = min(diff, nums[n-3]-nums[1]);
        
        return diff;
        
        
    }
};