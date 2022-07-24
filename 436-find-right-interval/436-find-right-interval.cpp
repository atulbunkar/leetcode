class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& it) {
        map<int,int> mp; //st,ind
        
        int idx=0;
        for(auto x:it){
            mp[x[0]] = idx;
            idx++;
        }
        
         vector<int> ans;
        
        for(auto x:it){
            auto i = mp.lower_bound(x[1]);
            
            if(i==mp.end())ans.push_back(-1);
            
            else{
                ans.push_back(i->second);
            }
            
        }
        return ans;
        
        
    }
};