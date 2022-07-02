class Solution {
public:
    int mem[102][102][50];
    int solve(vector<int>& house, vector<vector<int>>& cost, int m, int n,int i,int t,int prev)    {
        if(i == m){
            if(t==0)
                return 0;
            return 1e8;
        }
        
        if(t<0)return 1e8;
        
        if(mem[i][t][prev+1] != -1)return mem[i][t][prev+1] ;
        
        if(house[i]!=0){
            int x =0;
            if(prev==house[i])
                x= solve(house,cost,m,n,i+1,t,prev);
            else
                x =solve(house,cost,m,n,i+1,t-1,house[i]);
            return  mem[i][t][prev+1] = x;
        }
        else{
            int x=1e8;
            for(int ind =0;ind<n;ind++){
                if(prev==ind+1)
                    x = min(x,cost[i][ind] + solve(house,cost,m,n,i+1,t,ind+1));
                else
                     x = min(x,cost[i][ind] + solve(house,cost,m,n,i+1,t-1,ind+1));
            }
            return  mem[i][t][prev+1] = x;
        }
    }
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int t) {
        memset(mem,-1,sizeof(mem));
        int x = solve(houses,cost,m,n,0,t,-1) ;
        
        return x ==1e8 ? -1:x;
    }
};