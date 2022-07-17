class Solution {
public:
    int maxSumRangeQuery(vector<int>& nums, vector<vector<int>>& r) {
        int mod = 1e9 + 7;
        int n = nums.size();
        vector<int> freq(n,0);
        
        for(auto x:r){
            freq[x[0]]++;
            if(x[1]+1<n)freq[x[1]+1]--;
        }
        
        long long sum=0;
        
        for(int i=1;i<n;i++){
            freq[i] += freq[i-1];
        }
        
        sort(freq.begin(),freq.end());
        sort(nums.begin(),nums.end());
        
        for(int i=0;i<n;i++){
            sum = sum + ((long long)freq[i]*nums[i])%mod;
            sum = sum%mod;
        }
        return sum;
        
    }
};