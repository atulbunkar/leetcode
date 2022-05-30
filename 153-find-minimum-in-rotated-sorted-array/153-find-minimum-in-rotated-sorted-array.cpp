class Solution {
public:
    int findMin(vector<int>& nums) {
        
        int n = nums.size(); 
        
        int  i = 0 , j = n-1, mid;
        
        while(i<j){
            
            mid = (i+j)/2;
            
            if(mid<n and nums[mid] > nums[mid+1])return nums[mid+1];
            if(mid>0 and nums[mid] < nums[mid-1])return nums[mid];
            
            if(nums[n-1] > nums[mid]){
                j = mid-1;
            }
            else{
                i = mid+1;
            }
            
        }
        
        return nums[i];
    }
};