class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int minpr = 1 , maxpr = 1;
        int ans = -1e9;
        for(auto &it : nums){
            if(it < 0) 
                swap(minpr,maxpr);
            minpr = min(minpr*it,it);
            maxpr = max(maxpr*it,it);
            ans = max(ans,maxpr);
        }
        return ans;
    }
};