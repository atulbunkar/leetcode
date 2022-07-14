class Solution {
public:
    int dir[4][2] = {{0,-1},{-1,0},{0,1},{1,0}};  int ans=0 ;int tmp ; map<int,int> mp;        
    
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> clr(n,vector<int>(m,0));
        int c = 2; 
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!clr[i][j] and grid[i][j]){
                    color(i,j,c,grid,clr);
                    c++;
                }
            }
        }
        
        // for(auto x:clr)
        // {
        //     for(auto y:x)cout<< y<< " ";
        //     cout<<endl;
        // }
        
               //clr,size;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(clr[i][j]){
                    mp[clr[i][j]]++;
                    ans = max(ans,mp[clr[i][j]]);
                }
            }       
        }
        
       
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
          
                if(!grid[i][j]){
                    tmp=0;
                    findsize(i,j,clr);
                    ans = max(ans,tmp+1);
                }       
            }
        }
    return ans;
    }
    
    void findsize(int i,int j,vector<vector<int>> &clr){
        set<int> t; 
        int n = clr.size(), m = clr[0].size();
        if(i>0){
            if(t.find(clr[i-1][j] ) == t.end() ){
                tmp+= mp[clr[i-1][j]];
                t.insert(clr[i-1][j]);
            }
        }
        if(j>0){
            if(t.find(clr[i][j-1] ) == t.end() ){
                tmp += mp[clr[i][j-1]];
                t.insert(clr[i][j-1]);
            }
        }
        
        if(i<n-1){
            if(t.find(clr[i+1][j] ) == t.end() ){
                tmp+= mp[clr[i+1][j]];
                t.insert(clr[i+1][j]);
            }
        }
        if(j<m-1){
            if(t.find(clr[i][j+1] ) == t.end() ){
                tmp+= mp[clr[i][j+1]];
                t.insert(mp[clr[i][j+1]]);
            }
        }
        
        return ;
    }
    
    
    
    
    
    void color(int i,int j, int c, vector<vector<int>>& grid,vector<vector<int>> &clr){
        int n = grid.size(), m = grid[0].size();
        if(i<0 || j<0 || i>= n|| j>=m || !grid[i][j] || clr[i][j])return ;
        clr[i][j] = c;
        for(auto x:dir){
            color(i+x[0], j+x[1] , c,grid,clr);
        }
    }
};