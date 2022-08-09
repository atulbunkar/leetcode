class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& r) {
        map<double,long long> mp;
        
        for(auto x:r){
            double k = x[0]*1.0/x[1];
            mp[k]++;
        }
        
        long long ans=0;
        for(auto x:mp){
            long n = x.second;
            ans += n*(n-1)/2;
        }
        return ans;
    }
};