class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size(); int ret=0,old=0,curr=0;
        
        for(int i=1;i<n-1;i++){
            
            if(i<n-1 and nums[i]-nums[i-1] == nums[i+1]-nums[i]){
                curr = old+1; 
                
            }
            ret += curr;
            old = curr;
            curr = 0;
            
        }
        return ret;
    }
    
};