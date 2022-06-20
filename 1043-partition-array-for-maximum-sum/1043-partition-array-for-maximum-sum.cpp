class Solution {
public:
    vector<int> dp;
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size(); dp.resize(n+1,-1);
        return dfs(0,arr,k);
    }
    int dfs(int i ,vector<int>& arr, int k){
        if(i>=arr.size() )return 0; int ans = 0; int maxx = -1;
        int nums=0;
        
        if(dp[i]>-1)return dp[i];
        
        for(int m=i; m< i+k ;m++){
            if(m>=arr.size())break;
            
             maxx = (max(maxx,arr[m])); //store largest for curr window, winlen is changing 1 to k
             nums++;                    //nums in curr window
            
            ans = max(ans, (nums)*maxx + dfs(m+1,arr,k) ); //max(ans, max(left part + right part))
        }
        return dp[i] = ans;
    }
};