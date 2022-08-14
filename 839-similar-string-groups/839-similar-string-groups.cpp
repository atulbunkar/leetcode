class Solution {
public:
    vector<int> par;
    
    int numSimilarGroups(vector<string>& strs) {
        int n =strs.size();
        par.resize(n,-1);
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(strs[i],strs[j]))join(i,j);
            }
        }
        
        int ans =0;
        for(auto& x:par)ans += x==-1;
        return ans;
    }
    
    int find(int i){
        if(par[i]!=-1)return find(par[i]);
        return i;
    }
    
    void join(int i,int j){
       int x = find(i); int y = find(j);
        
        if(x!=y)par[y] = x;
    
    }
    
    bool check(string& s1, string&s2){
        
        int n = s1.size(); int d = 0;
        for(int i=0;i<n;i++){
            if(s1[i] != s2[i])d++;
        }
        
        return d==2 || d==0;
        
    }
};