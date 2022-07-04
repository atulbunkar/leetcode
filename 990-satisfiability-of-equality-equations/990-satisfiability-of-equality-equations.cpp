class Solution {
public:
    int pr[27];
    int sz[27];
    int find(int v){
        if(pr[v] == -1)
            return v;
        
        return pr[v] = find(pr[v]);
    }
    void un(int a,int b){
        a = find(a);
        b = find(b);
        if(a == b)
            return ;
        if(sz[a]<sz[b])
            swap(a,b);
        pr[b] = a;
        sz[a] = sz[a]+sz[b];
        return;
    }
    
    bool equationsPossible(vector<string>& eq) {
        memset(pr,-1,sizeof(pr));
        memset(sz,1,sizeof(sz));
        for(auto &x:eq){
            if(x[1] == '='){
                un(x[0]-'a',x[3]-'a');
            }
            
        }
        for(auto &x:eq){
             if(x[1] == '!'){
                    int l = find(x[0]-'a');
                    int r = find(x[3]- 'a');
                    if(l==r)
                        return 0;
                }
            
        }
            
        return 1;
    }
};