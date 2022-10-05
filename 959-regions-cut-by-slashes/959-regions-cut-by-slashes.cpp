class Solution {
public:
    bool vst[100][100];
    vector<pair<int,int>> dir = { { 1,0 } , { 0,1 } , { -1,0 } , { 0,-1 } };
    
    void dfs(vector<vector<int>> &v, int i, int j){
        int n = v.size();
        if(i<0 || j<0 || i >= n || j>= n )return;
        vst[i][j] =1;
        
        for(auto d:dir){
            int ni = i + d.first; int nj = j + d.second;
            if(ni<0 || nj<0 || ni >= n || nj>= n )continue;
            if(v[ni][nj]==1 and !vst[ni][nj])dfs(v,ni,nj);   
        }
        return;
    }
    
    int regionsBySlashes(vector<string>& g) {
        int n = g.size();
        memset(vst,false,sizeof(vst));
        vector<vector<int>> v(3*n, vector<int>(3*n,1));
        //cout<< 3*n <<endl;
        int m = 3*n ;
        for(int i=0; i<n;i++){  
            for(int j=0;j< g[i].size(); j++){
                if(g[i][j] == ' ' )continue;
                else if(g[i][j] == '/'){
                    v[3*i][3*j+2] = 0;
                    v[3*i+1][3*j+1] = 0;
                    v[3*i+2][3*j] = 0;
                }
                else{
                    v[3*i][3*j] = 0;
                    v[3*i+1][3*j+1] = 0;
                    v[3*i+2][3*j+2] = 0;
                  
                }
            }
        }
//         for(auto x:v){
//             for(auto y:x)cout<< y<< " ";
//             cout<<endl;
//         } 
        int comps = 0;
        for(int i=0;i<v.size();i++){
            for(int j=0;j<v[0].size();j++){
                if(v[i][j] ==1 and !vst[i][j]){dfs(v,i,j); comps++;}
                
            }
        }
        return comps;
    }
};