class Solution {
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return atm(nums,k) - atm(nums,k-1);
    }
    
    int atm(vector<int>& nums, int k){
        
        unordered_map<int,int> mp;
        int i=0,j=0;
        int n = nums.size(); int ans=0;
        
        if(k<=0)return 0;
        
        for(int i=0;i<n;i++){
            
            mp[nums[i]]++;
            
            while(mp.size()>k){
                if(mp[nums[j]]-- == 1)mp.erase(nums[j]);
                j++;
            }
            
            ans += i-j+1;
        }
        return ans;
        
    }
};