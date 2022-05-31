class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& p) {
        if(!canFinish(n,p))return {};
        
       vector<vector<int>> adj(n);
        
        
        if(n==1)return {0};
        
        for(auto x:p){
            adj[x[0]].push_back(x[1]);
        }
        
        vector<int> ans, done(n,0);
        
        while(ans.size()<n){
            
            for(int i=0; i< n; i++){
                if(done[i])continue;
                
                if(size(adj[i]) == 0){
                    done[i] = 1;
                    ans.push_back(i);
                    continue;
                }
                
                bool clr = true;
                for(auto j:adj[i]){
                    if(!done[j]){clr = false; break;}
                }
                if(clr){
                    done[i] = 1;
                    ans.push_back(i);
                }
                
                
            }
            
        }
        
        return ans;
            
    }
    
    
    
    
    
    
   bool iscycle(vector<int> adj[],vector<int> &vis,int id){
        if(vis[id]==1)
            return true;
        if(vis[id]==0){
            vis[id]=1;
            for(auto edge : adj[id]){
                if(iscycle(adj,vis,edge))
                    return true;
            }
        }
        vis[id] = 2;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> adj[n];
        for(auto edge : pre)
            adj[edge[1]].push_back(edge[0]);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(iscycle(adj,vis,i))
                return false;
        }
        return true;
    }
};