class Solution {
public:
     vector<int> par;
    
    int find(int i){
        if(par[i]==-1)return i;
         return find(par[i]);
    }
   
    
    int removeStones(vector<vector<int>>& s) {
       int cnt =0; int mr=0,mc=0;
        int n = s.size();
        par.resize(n,-1);  int comps = n;
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                
                if(s[i][0] ==s[j][0] || s[i][1]==s[j][1]){
                    int x = find(i);
                    int y = find(j);
                    
                    if(x!=y)par[x] = y;
                }
                
            }
        
        }
        
        comps = 0;
        for(auto x:par)if(x==-1)comps++;
       
      
        return n - comps;
    }
    
    
    
};