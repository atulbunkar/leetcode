class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size(); int ret=0,prevlen=0,curr=0;
        
        for(int i=1;i<n-1;i++){
            
            if(nums[i]-nums[i-1] == nums[i+1]-nums[i]){
                curr = prevlen+1;
         
            }
           
            ret += curr;
            prevlen = curr;
            curr = 0;
            
        }
        return ret;
    }
    
};