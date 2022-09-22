class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> indeg[n+1] ;
        
        queue<int>q ; vector<int> ans;
        int i = 0;
        
        
        
        for(auto &x:graph){
            for(auto &ney:x)indeg[ney].push_back(i);
            
            if(x.size()==0){q.push(i); ans.push_back(i);}
            i++;
            
        }
        
        i=0;         vector<int> out(n,0);

        for(auto &x:graph){
            out[i] = x.size();
            i++;
        }
        
        
        while(!q.empty()){
            
            int x = q.front(); q.pop();
            for(auto &come:indeg[x]){
                out[come]--;
                if(out[come]==0){
                    ans.push_back(come);
                    q.push(come);
                }
            }
            
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};