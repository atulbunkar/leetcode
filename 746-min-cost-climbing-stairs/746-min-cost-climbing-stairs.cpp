class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if(n==2)return min(cost[0],cost[1]);
        
        vector<int> mem(n+1,-1);
        return dp(n,cost,mem);
    }
    
    int dp(int i ,vector<int>& cost , vector<int>& mem){
        if(i<2)return cost[i];
        
        if(mem[i] != -1)return mem[i];
        
        if(i == cost.size()){
            return min(dp(i-1,cost,mem) , dp(i-2,cost,mem));
        }
        else{
            return mem[i] = cost[i] + min(dp(i-2,cost,mem) , dp(i-1,cost,mem));
        }
        
    }
    
    
};