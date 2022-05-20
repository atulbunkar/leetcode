class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> t(n+1,0);
        
        for(auto x:nums)
            if(x>=0 and x<=n)
                t[x]++;
        
        int i=1;
        for(i;i<=n;i++)
            if(t[i]==0)
                return i;
        
        return i;
    }
};