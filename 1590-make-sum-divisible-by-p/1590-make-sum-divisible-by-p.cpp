class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
       int find=0;
        for (auto &a : nums)
            find = (find + a) % p;
        
        long long sum =0, n = nums.size();
        unordered_map<int, int> last ; last[0] = -1;
        int ans = n;
        
        for(int i=0;i<n;i++){
            sum += nums[i];
            
            last[sum%p] =i;          
            int want = (sum - find + p)%p;
            
            if(last.count(want))
                ans = min(ans, i-last[want]);
            
        }
        
        return ans==n ? -1: ans;
    }
};