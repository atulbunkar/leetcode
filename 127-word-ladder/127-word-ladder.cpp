class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& wl) {
        wl.push_back(bw);
        int n=wl.size(); 
        if(find(wl.begin(),wl.end(), ew) == wl.end())return 0;
        
        vector<int> adj[5001];
        
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                if(check(wl[i],wl[j])){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        queue<int> q; 
        vector<bool> vstd(n+1,false);
        q.push(n-1); int step =1;
        
        while(!q.empty()){
            int m = q.size();
           // bool flag = false;
            for(int j=0;j<m;j++){
                
                int curr = q.front(); q.pop();
                
                if(wl[curr]==ew)return step;
                
                //if(adj[curr].size() >0)flag =true;
                
                for(auto &i:adj[curr]){
                    if(vstd[i] || wl[i] == bw)continue;
                       // cout<< curr<< " "<< wl[i] << " "<<endl;
                    vstd[i] = true;
                    q.push(i);
                }
            }
           // if(!flag)return 0;
            step++;
        }
        return 0;
    }
    
    
    bool check(string& i, string& j){
        if(i.size() != j.size())return 0;
         int c =0;
        for(int k=0 ; k<i.size();k++)if(i[k] != j[k])c++;
        return c==1;
    }
};