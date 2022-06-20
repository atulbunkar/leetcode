class Solution {
public:
    int f; vector<vector<int>> mp; 
    
    int maxProfit(vector<int>& p, int fee) {
        f = fee;  mp.resize(p.size()+1, vector<int>(2,-1));
            
        return dp(0,0,p);
    }
    
    int dp(int i , int buy ,vector<int>& nums){ //buy -> 0 not bought, 1 ->bought
        
        if(i>=nums.size())return 0;
        
       
        if(mp[i][buy] >-1) return mp[i][buy] ;
        
        if(buy){ 
             return mp[i][buy] = max(dp(i+1,1 ,nums ) , dp(i+1,0, nums) +nums[i]-f );   
        }
        else{
            return mp[i][buy]= max( dp(i+1,1,nums)-nums[i] , dp(i+1,0,nums)  );
        }
        
        
    }
};