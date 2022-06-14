class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n= nums.size();
        
        int i=0, j=n-1;
        int p ,q ;
        
        p = nums[i]*nums[i+1]*nums[j];
        q = nums[j]*nums[j-1]*nums[j-2];
        
        
        return p>q ? p:q;
    }
};