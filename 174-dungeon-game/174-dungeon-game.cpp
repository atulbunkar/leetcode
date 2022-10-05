class Solution {
public:
    vector<vector<int>> dp;
    int helper(vector<vector<int>> & dun,int i,int j,int m,int n){
        if(i == m || j == n)
            return 1e5;
        if(i == m-1 && j == n-1)
            return max(0,-dun[i][j]);
        if(dp[i][j] != -1)
            return dp[i][j];
        int x = max(0,-dun[i][j]+helper(dun,i+1,j,m,n));
        int y = max(0,-dun[i][j]+helper(dun,i,j+1,m,n));
        return dp[i][j] = min(x,y);
    }
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int m = dungeon.size();
        int n = dungeon[0].size();
        dp.resize(m,vector<int>(n,-1));
        return helper(dungeon,0,0,m,n)+1;
    }
};