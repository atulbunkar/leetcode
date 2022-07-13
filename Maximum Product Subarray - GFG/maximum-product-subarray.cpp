// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:
     
	// Function to find maximum product subarray
	long long maxProduct(vector<int> nums, int n) {
	 long long mx = nums[0],mn = nums[0] ,ans=nums[0];
	 
	 for(int i=1;i<n;i++){
	     if(nums[i]<0)swap(mx,mn);
	     
	     mx = max((long long)nums[i], mx*nums[i]);
	     mn = min((long long)nums[i], mn*nums[i]);
	     
	     ans = max(ans,mx);
	     
	 }
	    return ans;
	}

};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends