class Solution {
public:
    int mem[101][202][2];
    int stoneGameII(vector<int>& p) {
        memset(mem,-1,sizeof(mem));
         int n =p.size();
        
        return dp(0,1,1,p);
    }
    
    int dp(int i,int m, int a,vector<int>& p){
        int n =p.size();
        if(i==n)return 0;
        
        if(mem[i][m][a]!=-1)return mem[i][m][a];        
        int s;
        if(a)s = 1;
        else s = -1;
        
        int ans=0;
         if(a)ans = 0;
        else ans = 1e6;
        
        
        int sum =0;
        
        for(int x = i; x < i+2*m and x < n ; x++){
            sum += p[x];
            if(a)
                ans = max( dp(x+1,max(m,(x-i+1)),1-a,p )+sum , ans);
            else
                ans = min( dp(x+1,max(m,(x-i+1)),1-a,p ) , ans);
        }
        
        return mem[i][m][a]= ans ;
    }
};