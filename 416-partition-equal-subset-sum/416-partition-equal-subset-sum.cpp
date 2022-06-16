class Solution {
public:
    bool found = false;
    bool canPartition(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        
        int n =arr.size();
        
        int sum =0;
        for(auto x:arr)sum += x;
         if(sum%2)return false;
        sum /= 2;
        
        vector<vector<bool>> dp(n+1, vector<bool>(sum+1));
        
        dp[0][0] = true;
            
        for(int i= 1; i<=sum ;i++)
            dp[0][i] = false;
        
        for(int i=1;i<=n ;i++)
            dp[i][0] = true;
    
        
        for(int i=1; i<=n ;i++){
            
            for(int j=1; j<=sum; j++){
                
                dp[i][j] = dp[i-1][j];
                
                if(arr[i-1]>j)continue;
                
                dp[i][j] = dp[i-1][j-arr[i-1]] || dp[i][j];
                    
            }
        }
        return dp[n][sum];
    
    }
        
    
};