class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(); int m = grid[0].size();
        
        vector<vector<bool>> vstd(n,vector<bool>(m,false)); int ans=0;
        
        for(int i=0; i <n; i++){
            for(int j=0; j<m; j++){
                
                if(!vstd[i][j] and grid[i][j] =='1'){
                    bfs(grid,vstd,i,j);
                    ans++;
                }
                
            }
        }
        return ans;
        
    }
    
    void bfs(vector<vector<char>>& grid , vector<vector<bool>>& vstd , int i, int j){
        int n = grid.size(); int m = grid[0].size();
        if(i<0 || i>=n || j<0 || j >= m)return;
        
        if(vstd[i][j] || grid[i][j] == '0')return;
        
        vstd[i][j] = true;
        
        bfs(grid,vstd,i+1,j);
        bfs(grid,vstd,i,j+1);
        bfs(grid,vstd,i-1,j);
        bfs(grid,vstd,i,j-1);
       
       

    }
};