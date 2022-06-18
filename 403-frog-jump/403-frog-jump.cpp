class Solution {
public:
    map<pair<int,int>,bool> mem;
    bool canCross(vector<int>& s) {    
        return dfs(1,1,s);

    }
    bool dfs(int i, int k, vector<int>& s){
        if(i== s[s.size()-1])return true;
        
        if(k==0)return false;
        
        if(mem.find(make_pair(i,k)) != mem.end() )return mem[make_pair(i,k)];
        
        auto it = lower_bound(s.begin(), s.end() ,i) ;  
        
        if(it== s.end() || *it != i)return false;
        
        return mem[make_pair(i,k)] = dfs( i+k+1,k+1,s) || dfs( i+k-1,k-1,s) || dfs(i+k,k,s);
    }
};