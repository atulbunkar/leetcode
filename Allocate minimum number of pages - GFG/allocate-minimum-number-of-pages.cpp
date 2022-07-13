// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    int findPages(int nums[], int N, int M) 
    {
        int min=0,max=0;
        for(int i=0;i<N;i++)max += nums[i];
        int ans = -1;
        
        if(M>=N)return nums[N-1];
        
        while(min<=max){
            int mid = (max+min)/2; // mid is curr 
            int run =0; int k=M; bool f = false; int p=0;
           // cout<< mid << "-> ";
            for(int i=0;i<N;i++){
                
                if(run+nums[i] > mid ){ //check if adding curr num will overflow mid
                    if(k==1 || nums[i]>mid){f = true;break;}
                    else k--;
                    run = nums[i]; //tricky part , set to curr num after partition
                }
                else                //only run sum when no partition
                    run += nums[i];
            }    
            //cout << f<< " ";
            if(f){
                min = mid+1;
            }
            else {
                ans = mid;
                max = mid-1; 
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends