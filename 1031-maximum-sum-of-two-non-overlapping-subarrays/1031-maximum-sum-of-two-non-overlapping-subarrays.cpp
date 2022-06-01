class Solution {
public:
    int maxSumTwoNoOverlap(vector<int>& nums, int f, int s) {
        int ans = 0;
        int n = nums.size();
        
        //return help(nums,f,s);
        
        return max(help(nums,s,f),help(nums,f,s));
  
    }
    
    int help(vector<int>& nums , int f,int s){
        int ans = 0;
        int n = nums.size(); 
        vector<int> dp1(n,0), dp2(n,0);
        vector<int> numss = nums , numss2 = nums;
        
        dp1[0] = nums[0]; dp2[n-1] = nums[n-1];
        
        for(int i=1; i<n;i++)
            numss[i] += numss[i-1];
        
        for(int i=1;i < n ; i++){
            
            if(i<f){
                dp1[i] = nums[i] + dp1[i-1];
            }
            else{
                int j = i-f;
                dp1[i] = max(dp1[i-1], numss[i]-numss[j] );
            }
            
        }
        
        int l= 1;
        for(int i = n-2; i>=0; i--)
            numss2[i] += numss2[i+1];
        
        for(int i=n-2; i>=0; i--){
            
            if(l++ <s){
                dp2[i] = nums[i] + dp2[i+1] ;
            }
            else{
                int j = i+s ;
                dp2[i] = max(dp2[i+1], numss2[i] - numss2[j]  );
            }
            
        }
        
        ans = 0;
        for(int i=f-1; i<n-s; i++){
            
            ans = max(ans, dp1[i]+dp2[i+1]);
            
        }
        
        return ans;
    }
    
    
};