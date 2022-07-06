class Solution {
public:
    int dir[4][2] = {{0,1}, {1,0}, {0,-1},{-1,0}} ;
    int mem[201][201];  bool v[201][201];
    
    int longestIncreasingPath(vector<vector<int>>& mt) {
        memset(mem,-1,sizeof(mem)); int ans=0;
        memset(v,false,sizeof(v)); 
        
        int n= mt.size(); int m = mt[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans = max(ans , dfs(i,j,mt));
            }
        }
        return ans;
    }
    
    int dfs(int i,int j, vector<vector<int>>& mt){
        //if(i<0 || j<0 || i>=mt.size() || j>= mt[0].size())return INT_MIN;
        int ans=1;
        if(mem[i][j] !=-1)return mem[i][j];
        v[i][j] =1;
        
        for(int k=0;k<4;k++){
            int ii = i+dir[k][0]; int jj = j+dir[k][1];
            if(ii<0 || jj<0 || ii>= mt.size() || jj>= mt[0].size() || v[ii][jj])continue;
            
            if(mt[ii][jj] > mt[i][j]){
                
                ans = max(ans, 1+dfs(ii,jj,mt) );
            }
        }
        
        v[i][j] = 0;
        return mem[i][j] = ans;
    }
    
};