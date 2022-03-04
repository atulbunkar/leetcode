class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n= nums.size() ;
        
        //sum(n) = n(n+1)/2
        
        int s = 0;
        for(auto x:nums)
            s += x;
        
        int ss = n*(n+1)/2;
        
        return ss-s;
        
    }
};