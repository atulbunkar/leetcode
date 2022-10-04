class Solution {
public:
    int maxSum(vector<vector<int>>& g) {
        
        int n = g.size();
        int m  = g[0].size();
        
        long ans = -1;
        for(int i=0; i < n-2; i++){
            
            for(int j=0; j<m-2; j++){
                
                long x =  1L*g[i][j] + 1L*g[i][j+1] + 1L*g[i][j+2] + 1L*g[i+1][j+1] + 
                         1L*g[i+2][j] + 1L*g[i+2][j+1] + 1L*g[i+2][j+2];
                
                ans = max(ans,x);
                
            }
            
        }
        return ans;
    }
};