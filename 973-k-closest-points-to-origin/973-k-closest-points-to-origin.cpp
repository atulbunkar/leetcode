#include <math.h>
class Solution {
public:
   
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        priority_queue<int ,vector<int> ,greater<int>> pq;
        int c; unordered_map<int, vector<vector<int>> > mp; 
        
        for(auto x:p){
            c = x[0]*x[0] + x[1]*x[1];
            mp[c].push_back({x[0],x[1]});
            pq.push(c);
        }
        vector<vector<int>> ans;
        
        while(k>0){
            auto x = mp[pq.top()];
            ans.insert(ans.end(), x.begin(), x.end() );
            pq.pop();
            k -= x.size();
            //cout<< k;
        }
        
            
        return ans;
    }
};