class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<int> pref(n,0) ; 
        pref[0] = nums[0];
       
        int temp =0;
        
        unordered_map<int,int> mp; //ele, count;
        
        int ans = -1,j=0;
        
        for(int i=0; i<n;i++){
            
            mp[nums[i]]++; temp += nums[i];
            
            while(j<i and mp[nums[i]]>1){
                mp[nums[j]]--;
                temp -= nums[j];
                j++;
                
            }
            
          //  int s = pref[i] - ( (j>0) ?pref[j-1] : 0 );
            
            ans = max(ans, temp);
            
        }
        
        return ans;
        
    }
};