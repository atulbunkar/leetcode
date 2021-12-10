class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxR = 0 , curR = 0 , n = nums.size();
        if(n==1)return true;
        
        for(int i = 0 ; i < n ; i++ ){
            
            if(maxR < i )return false;
            
            if(i+ nums[i] > maxR){maxR = i+nums[i];  }
  
        }
        
        
        return true;
    }
};