class Solution {
public:
    int maxWidthRamp(vector<int>& nums) { 
        vector<pair<int,int>> st;
        st.push_back(make_pair(nums[0],0));
        
        int ans = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] < st.back().first)
                st.push_back(make_pair(nums[i],i));    //stack is decreasing monotonic stack
            
            else                         //search in st for distance
            {
                int lb = lower_bound(st.begin(), st.end(), make_pair(nums[i],i), greater<pair<int,int>>())->second;
                
                ans = max(ans,i-lb);
            }
            
        }
        return ans;
    }
};