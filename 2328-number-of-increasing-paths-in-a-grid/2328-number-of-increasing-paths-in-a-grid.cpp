class Solution {
public:
    int mod = 1000000007;  int dir[4][2] = {{0,1}, {1,0}, {0,-1},{-1,0}} ;
    int mem[1001][1001];  bool v[1001][1001];
    
    int countPaths(vector<vector<int>>& mt) {
        memset(mem,-1,sizeof(mem)); int ans=0;
        memset(v,false,sizeof(v)); 
        
        int n= mt.size(); int m = mt[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans += (long long)dfs(i,j,mt)%mod;
                ans = ans%mod;
            }
        }
        return ans%mod ;
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
                
                ans += (long long)dfs(ii,jj,mt)%mod ;
                ans = ans%mod;
            }
        }
        
        v[i][j] = 0;
        return mem[i][j] = (int)ans%mod;
    }
};