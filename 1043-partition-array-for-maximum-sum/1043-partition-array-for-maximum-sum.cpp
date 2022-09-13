class Solution {
public:
    int mem[501];
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(mem,-1,sizeof(mem));
        return dp(0,arr,k);
        
    }
    
    int dp(int i, vector<int>& arr, int k ){
     
        if(i>=arr.size())return 0; 
        
        if(mem[i]>-1)return mem[i];
        
        int mx = arr[i];
        int ans = -1;
        
        for(int s = i; s<i+k and s< arr.size() ; s++){
            
            mx = max(mx,arr[s]);
            
            ans = max(ans , mx*(s-i+1) + dp(s+1,arr,k) );
            
        }
        
        return mem[i] = ans;
        
        
    }
};