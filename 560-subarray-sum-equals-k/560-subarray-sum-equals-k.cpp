class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        map<int,int> mp; //sum,idx
        //mp[sum-k] -> mp[0]==? latest idx
        
        mp[0]= 1;
        int ans=0;
        int n = nums.size(), sum =0;
        for(int i=0;i<n;i++){
            sum += nums[i];
            
            ans+= mp[sum-k];
            mp[sum]++;
        }
        
        return ans;
        
    }
};