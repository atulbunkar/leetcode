class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        multiset<int> s;
        
        int ans=0; int n=nums.size(); 
        for(int i=0;i<n;i++){
            
          if(nums[i]>=k)continue;
            auto it = s.find(k-nums[i]);
            if(it != s.end()){
                ans++;
                s.erase(it);
            }
            else{
                s.insert(nums[i]);
            }
            
        }
    return ans;
    }
    
};