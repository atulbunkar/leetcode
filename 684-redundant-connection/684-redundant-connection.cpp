class Solution {
public:
    vector<int> p;
    int find(int i)
    {
        if(p[i] == -1)return i;
        return find(p[i]);
    }
    vector<int> findRedundantConnection(vector<vector<int>>& e) {
        
        
        int n = 0;
        for(auto x:e){
            n = max(n,x[0]);
            n = max(n,x[1]);
        }
        
        p.resize(n+1,-1);    vector<int> ans;
        
        for(auto x:e){
            
            int h = find(x[0]);
            int j = find(x[1]);
            
            if(h != j){
                p[h] = j;
            }
            else{
                ans = x;
            }
            
        }
        
        
        return ans;
    }
};