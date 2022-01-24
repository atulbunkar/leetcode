class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size(); //store 1 in 0;
     
 
        for(int i= 0;i<n;i++){
            nums[abs(nums[i])-1] = nums[abs(nums[i])-1] > 0 ? -nums[abs(nums[i])-1] : nums[abs(nums[i])-1];
        }
        vector<int> ans;
        
        for(int i= 0;i<n;i++){
            if(nums[i] >0)
                ans.push_back(i+1);
        }
            
        return ans;
    }
};