class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n,0) ; 
        pref[0] = nums[0];
       
        for(int i=1;i<n;i++){
            pref[i] = pref[i-1] + nums[i];
            //cout<< pref[i] << " ";
        }
        
        unordered_map<int,int> mp; //ele, count;
        
        int ans = -1,j=0;
        
        for(int i=0; i<n;i++){
            
            mp[nums[i]]++;
            
            while(j<i and mp[nums[i]]>1){
                mp[nums[j]]--;
                j++;
            }
            
            int s = pref[i] - ( (j>0) ?pref[j-1] : 0 );
            
            ans = max(ans, s);
            
        }
        
        return ans;
        
    }
};