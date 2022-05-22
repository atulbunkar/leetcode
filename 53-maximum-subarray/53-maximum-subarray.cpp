class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans= INT_MIN , temp = 0;
        if(nums.size() ==1)return nums[0];
        
        for(int i=0;i < nums.size(); i++){
            
            temp += nums[i];
            
            ans = max(ans,temp);
            if(temp <0)temp = 0;
            
  
        }
        return ans;
        
    }
};