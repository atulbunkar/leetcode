// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int n=arr.size();
        if(n==1)return arr;
        int j=n-1; bool flag =false;
        
        for(j;j>0;j--){
            if(arr[j-1]<arr[j]){
                //swap(arr[j-1],arr[n-1]);
                flag = true;
                break;
            }
        }
        
        j-=1; 
        if(flag)
            {
                for(int i=n-1; i>j; i--)
                {
                    if(arr[j] < arr[i]){
                        swap(arr[j],arr[i]);
                        reverse(arr.begin()+j+1,arr.end());
                        break;
                    }
                }
            }
            
        else
            reverse(arr.begin(),arr.end());
        
        return arr;
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}  // } Driver Code Ends