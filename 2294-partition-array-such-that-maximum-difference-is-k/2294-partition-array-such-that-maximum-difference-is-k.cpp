class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        vector<vector<int>> v;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        
        v.push_back({{nums[0]}}); 
        
        for(int i=1;i<n;i++){
            bool f=0;
            
            auto& x = v.back();
            
            if(abs(nums[i]-x[0])<=k)
                x.push_back(nums[i]);
            
            else
                v.push_back({{nums[i]}});
            
        }
        
        return v.size();
    }
};