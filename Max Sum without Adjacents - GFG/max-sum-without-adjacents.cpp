// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	// calculate the maximum sum with out adjacent
	int findMaxSum(int *nums, int n) {
	    vector<vector<int>> mem(n,vector<int>(2,-1));
	    
	    return max(dp(0,0,n,nums,mem) , dp(0,1,n,nums,mem));
	    
	}
	
	int dp(int i,int k, int n ,int *nums,  vector<vector<int>>& mem){
	    
	    if(i>=n)return 0;
	    
	    if(mem[i][k]>-1)return mem[i][k];
	    
	    if(k==1){
	        return mem[i][k] = dp(i+1,1-k,n,nums,mem);
	    }
	    
	    int x = max( dp(i+1,0,n,nums,mem), dp(i+1,1 ,n,nums,mem) + nums[i]);
	   
	   return mem[i][k] = x;
	    
	    
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.findMaxSum(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends