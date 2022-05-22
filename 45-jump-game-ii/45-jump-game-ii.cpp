class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 0, curR = 0, maxR = 0;
 
      
        
        for(int i=0 ;i < nums.size()-1; i++){
          
            curR = max(curR , i+nums[i]);
              if(i == maxR){
                ans++;
                maxR = curR;
            }
            
            
        }
        return ans;
    }
};