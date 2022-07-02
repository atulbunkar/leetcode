class Solution {
public:
    int mem[1001][102][2];
    int maxProfit(int k,vector<int>& p) {
        int n = p.size();  memset(mem,-1,sizeof(mem));
        
        return dp(0,k,1,p);
    }
    
    int dp(int i, int k, int buy, vector<int>& p){
        if(i==p.size() || k==0)return 0;
        
        if(mem[i][k][buy] !=-1)return mem[i][k][buy];
        
        if(buy){ // can buy
            return mem[i][k][buy] =  max( dp(i+1,k,0,p)-p[i] , dp(i+1,k,1,p) );
            
        }
        else{
            return mem[i][k][buy] = max( dp(i+1, k-1, 1,p)+p[i] , dp(i+1,k,0,p) ) ;
         
        }
        
    }
};