class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int ans=1;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        
       int newmin = nums[0];
        
        for(int i=1;i<n;i++){
            bool f=0;
            
            if(abs(nums[i]-newmin)<=k)
               continue;
            
            else{
                ans++;
                newmin = nums[i];
            }

            
        }
        
        return ans;
    }
};