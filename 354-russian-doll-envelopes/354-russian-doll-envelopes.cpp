class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& e) {
        sort(e.begin() , e.end(),[](vector<int>& a, vector<int>& b){
            if(a[0]== b[0])
                return a[1] > b[1];
            return a[0] < b[0];
        } );
        
        int ans = 0; int mx = -1;
        
        int n = e.size();
        vector<int> lis;
        
        for(auto x:e){
            
            auto it = lower_bound(lis.begin(), lis.end(),x[1]);
            
            if(it == lis.end())lis.push_back(x[1]);
            else{
                *it = x[1];
            }
            
        }
        
        return lis.size();
        
        
    }
};