class Solution {
public:
    vector<string> ans;
    vector<string> findItinerary(vector<vector<string>>& t) {
        map<string , multiset<string>> adj;
        
        for(auto x:t){
            adj[x[0]].insert(x[1]);
        }
        
        string kk = "JFK";
        //adj[kk].erase(adj[kk].begin());
        dfs(kk,adj);
        ans.push_back(kk);
        reverse(ans.begin(),ans.end());
        
        return ans;
        
              
    }
    
    void dfs(string s, map<string , multiset<string>>& adj ){
        
        
        while(!adj[s].empty()){
            auto x = (adj[s].begin());
            string st = *x;
            adj[s].erase(x);

            dfs(st,adj);
            ans.push_back(st);
        }
        
    }
};