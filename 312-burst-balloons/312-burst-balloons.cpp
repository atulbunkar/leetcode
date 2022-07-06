class Solution {
public:
    int mem[303][303];
    int maxCoins(vector<int>& nums) {
        memset(mem,-1,sizeof(mem));
        int n=nums.size();
        
        return dp(0,n-1,nums);
    }
    
    int dp(int i,int j ,vector<int>& nums){
        
        if(i>j)return 0;
        if(mem[i][j] != -1)return mem[i][j];
        int ans = 0;
        for(int k=i;k<=j;k++)
        {
            int l,r , prod;
            if(i==0)l=1; else l = nums[i-1];
            if(j==nums.size()-1)r=1; else r = nums[j+1];
            
            prod = nums[k] *l*r;
            
            ans = max({ans, dp(i,k-1,nums)+ prod + dp(k+1,j,nums) });
        }
        return mem[i][j] = ans;
        
    }
};