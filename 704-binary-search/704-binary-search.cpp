class Solution {
public:
    int search(vector<int>& nums, int t) {
        int n = nums.size();
        int i=0,j=n-1,mid;
        
        while(i<j){
            
            mid = (i+j)/2;
            if(nums[mid] == t)return mid;
            
            if(nums[mid]>t)j=mid-1;
            else
                i = mid+1;
        }
        return nums[i]==t ? i:-1;
    }
};