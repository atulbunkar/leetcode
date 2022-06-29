class Solution {
public:
    int dp[501][501];
    bool stoneGame(vector<int>& p) {
        int n=p.size(); 
        memset(dp,-1,sizeof(dp));
        
        int c = bt(p,0,n-1);
        
        return c>0 ? true :false;
        
    }
    
    int bt(vector<int>& p , int st, int end ){
        
        if(end==st)return p[st];
        
       if(dp[st][end] != -1)return dp[st][end];
        
       
        return dp[st][end]= max( p[st]+ bt(p,st+1,end ) , p[end] + bt(p,st,end-1));
  
        
    }
    

};