class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        
        int len=1,ans=0;
        
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1]){
                len++;
            }
            else{
                ans = max(len,ans);
                len = 1;
            }
        }
        return max(len,ans);
    }
};