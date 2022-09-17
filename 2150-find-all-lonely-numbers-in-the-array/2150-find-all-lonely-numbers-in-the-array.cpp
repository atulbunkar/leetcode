class Solution {
public:
    vector<int> findLonely(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> ans; int n = nums.size();
        
        if(n==1)return {nums[0]};
        
        for(int i=0;i<n;i++){
            
            if(i==0){
                if(nums[i+1]>nums[i]+1)ans.push_back(nums[i]); continue;
            }
            if(i==n-1){
                if(nums[i-1] < nums[i]-1)ans.push_back(nums[i]); continue;
            }
            
           if(nums[i+1]>nums[i]+1 and nums[i-1] < nums[i]-1)ans.push_back(nums[i]);
            
        }
        
      //  set<int> ret(ans.begin(),ans.end());
        
        return ans;
    }
    
};