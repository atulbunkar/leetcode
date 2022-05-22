class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR = 0 , curR = 0 , n = nums.size();
        if(n==1)return true;
        
        for(int i = 0 ; i < n-1 ; i++ ){
            maxR = max(maxR,i+nums[i]);
            
            if(maxR <= i)
                return false;
           
        }
        
        
        return true;
    }
};