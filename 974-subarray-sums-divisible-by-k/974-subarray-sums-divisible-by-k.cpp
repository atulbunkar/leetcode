class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int sum =0;
        map<int,int> mp;
        mp[0] =1;
        int n = nums.size() ,ans=0;
        
        for(int i =0;i<n;i++){
            
            sum += nums[i]; 
    
            while(sum-k<0 )sum+=k;
            
            ans += mp[(sum-k)%k];
            
            mp[sum%k]++;
            
        }
        return ans;
    }
};