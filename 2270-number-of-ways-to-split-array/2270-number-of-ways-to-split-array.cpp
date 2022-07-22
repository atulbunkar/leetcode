class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n =nums.size();
        vector<long long> pref;
        vector<long long> suff(n,0);
        
        long long sum=0;
        for(auto &x:nums){
            sum += x;
            pref.push_back(sum);
        }
        
        suff[n-1] = nums[n-1];
        for(int i=n-2; i>=0;i--){
            suff[i] = suff[i+1]+nums[i];
        }
        
        int ans=0;
        for(int i=0;i<n-1;i++){
          
            if(pref[i] >= suff[i+1] )
                ans++;
            
        }
        
        return ans;
        
    }
};