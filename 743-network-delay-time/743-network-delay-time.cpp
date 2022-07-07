class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> maxtime(n+1,INT_MAX);
        
        vector<pair<int,int>> adj[n+1];
        for(auto x:times){
            adj[x[0]].push_back({x[1],x[2]}); //pair -> dest,dist
        }
       maxtime[k] = 0;
       priority_queue<int, vector<int> , greater<int>> pq;
        pq.push(k);
        
        while(!pq.empty()){
            int p= pq.top(); pq.pop();
            
            for(auto x:adj[p]){
                if(maxtime[x.first] > maxtime[p] + x.second){
                    maxtime[x.first] = maxtime[p] + x.second;
                    pq.push(x.first);
                }
            }
        }
        
        int g = *max_element(maxtime.begin()+1, maxtime.end());
        return g==INT_MAX ? -1:g;
      
    }
    
   
    
    
};