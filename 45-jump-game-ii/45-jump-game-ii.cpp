class Solution {
public:
    int jump(vector<int>& nums) {
        int ans = 1, curR = 0, maxR = 0;
        int n= nums.size();
        if(n==1)return 0;
        
        curR = nums[0];
        
        for(int i=1; i<n-1;i++){
            
            maxR = max(maxR,i+nums[i]);
            
            if(i==curR){
                ans++;
                curR = maxR;
            }
            
        }
        
        return ans;
    }
};