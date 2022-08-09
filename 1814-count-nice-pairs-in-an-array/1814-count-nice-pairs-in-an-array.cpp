class Solution {
public:
    int countNicePairs(vector<int>& nums) {
        long long ans = 0;
        
        int n =nums.size();
        int mod = 1e9+7;
        
        unordered_map<int,long long> mp;
        for(int i=0;i<n;i++){
            int t = nums[i] - rev(nums[i]);
            mp[t]++;
        }
        
        for(auto x:mp){
        
            long long t = x.second;
            ans += 1L*t*(t-1)/2;
            ans = ans%mod;
            
        }
        
        return ans%mod;
    
    }
    
    int rev(int i){
        string k = to_string(i);
        reverse(k.begin(),k.end());
        return stoi(k);
    }
    
    
};