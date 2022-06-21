class Solution {
public:
    int mem[366][366+31] ;
    int mincostTickets(vector<int>& nums, vector<int>& cost) {
        memset(mem, -1, sizeof(mem));
        
        return min(dp(1,nums[0],nums,cost)+cost[0] , min(dp(1,nums[0]+6,nums,cost)+cost[1] ,                                           dp(1,nums[0]+29,nums,cost)+cost[2] ) );
    }
    
    int dp(int i, int expire , vector<int>& nums, vector<int>& cost){
        
        if(i==nums.size())return 0;
        
        if(mem[i][expire] >-1)return mem[i][expire];
        
        if(nums[i]>expire){
            return mem[i][expire] = min(dp(i+1,nums[i]+0 ,nums,cost)+cost[0] , min(dp(i+1,nums[i]+6,nums,cost)+cost[1] ,                                            dp(i+1,nums[i]+29,nums,cost)+cost[2] ) );
        }
        else{
            return mem[i][expire] = dp(i+1,expire,nums,cost);
        }
        
    }
    
};