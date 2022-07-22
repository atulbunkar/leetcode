class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n =nums.size();
        vector<long long> pref(1);
        vector<long long> suff(n,0);
        
        long long sum=0;          suff[n-1] = nums[n-1];
        pref[0] = sum = nums[0];
        
        for(int i=1;i<n;i++){
            sum += nums[i];
            pref.push_back(sum);
            
            suff[n-i-1] = suff[n-i]+nums[n-i-1];
        }
  
        
        int ans=0;
        for(int i=0;i<n-1;i++){
          
            if(pref[i] >= suff[i+1] )
                ans++;
            
        }
        
        return ans;
        
    }
};