class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        map<int,int> mp,loc ;
        int g=0,l=0; int idx = 0;
        
        for(auto &x:nums){
            mp[x] = idx;
            loc[x]++;
            g = max(g,loc[x]);    
            idx++;
        }
        
        int ans = 1e8;
        
        for(int i=0;i<nums.size() ;i++){
            
            if(loc[nums[i]] == g and mp.count(nums[i])){
                ans = min(ans, mp[nums[i]] -i +1);
                mp.erase(nums[i]);
            }
            
        }
        
        return ans;
        
        
        
    }
};