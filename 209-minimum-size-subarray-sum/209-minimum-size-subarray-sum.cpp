class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        

        int ans = n; bool f = false;
        
        vector<int> s(n+1,0); s[0] = 0;
        
       for(int i = 0 ; i < n ; i++){
            s[i+1] = s[i] + nums[i]; 
       }
        int z = 0; int sum; int l = 0; 
        
       
        
        for(int i=1; i <= n; i++){
            
            sum = s[i]-s[l];
            
            while(l<i and sum>=target){
                f = true;
                ans = min(ans,i-l);
                l++;
                sum = s[i]-s[l];
            }
             
        }
        
        return f?ans:0 ;
    }
};