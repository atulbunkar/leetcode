class Solution {
public:
    int matrixScore(vector<vector<int>>& g) {
        int n = g.size(), m = g[0].size();
        
        for(int i=0;i<n;i++){
            if(g[i][0]==0)
                swapp(g,i);
        }
         
       for(int j=0;j<m;j++){
           bool colz = col0(g,0,j);
           if(colz)swapp2(g,j);
       }
        
        int ans=0;
       for(int i=0;i<n;i++)
       {
           ans += b2i(g,i);
       }
        return ans;
        
    }
    
    int b2i(vector<vector<int>>& g, int i){
        
        int poww = 0; int ans =0;
        for(int j = g[0].size()-1; j>=0;j--){
            if(g[i][j])
                ans += pow(2,poww); 
            poww++;
        }
     return ans;   
    }
    
    
    void swapp(vector<vector<int>>& g, int i){
        for(int j =0; j< g[0].size(); j++)
            g[i][j] = 1-g[i][j];
    }
    
    void swapp2(vector<vector<int>>& g, int j){
        
        for(int i=0;i<g.size();i++)
            g[i][j] = 1-g[i][j];
        
    }
 
    
    int col0(vector<vector<int>>& grid ,int i, int j){ //get 0 count in col
        int z=0; int o=0;
        while(i<grid.size()){
            if(grid[i][j])o++;
            else 
                z++;
            i++;
        }
        return z>o ;
    }
    
};