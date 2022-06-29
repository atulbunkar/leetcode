class Solution {
public:
    int dp[501][501][2];
    bool stoneGame(vector<int>& p) {
        int n=p.size(); 
        memset(dp,-1,sizeof(dp));
        
        int c =bt(p,0,n-1,1);
        
        return c>0;
        
    }
    
    bool bt(vector<int>& p , int st, int end , int turn){
        
        if(end==st)return p[st];
        
        if(dp[st][end][turn] != -1)return dp[st][end][turn];
        
        if(turn){
            return dp[st][end][turn]= max( p[st]+ bt(p,st+1,end,0 ) , p[end] + bt(p,st,end-1,0));
        }
        else{
            return dp[st][end][turn] = -1 * max( p[st]+bt(p,st+1,end,1) , p[end]+bt(p,st,end-1,1) );
        }
        
    }
    

};