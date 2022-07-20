class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& gr, int m) {
        vector<pair<int,pair<int,int>>> v;
        
        int n = c.size(); int ans=0;
        
        for(int i=0;i<n;i++){
            if(gr[i]){
                
                for(auto& x:v){
                    int st = x.first , end = x.second.first;
                    
                    if(abs(i-st)<=m-1 and abs(i-end)<=m-1){
                        x.first = min(st,i);
                        x.second.first = max(end,i);
                        x.second.second = x.second.second+c[i];
                    }
                    
                }
                
                 v.push_back({i,{i,c[i]}});
            }
            else
                ans += c[i];
        }
        
        int mx=0;
        for(auto x:v){
            int st = x.first , end = x.second.first , g = x.second.second;
            
            mx = max(mx,g);
        }
        ans += mx;
        
        return ans;
    } 
};