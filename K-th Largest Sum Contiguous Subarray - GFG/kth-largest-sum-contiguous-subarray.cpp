// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int kthLargest(vector<int> &arr,int N,int k){
        priority_queue<int> sum ;
        
        for(int i=1;i<N ;i++){
            arr[i] += arr[i-1];
        }
        
        for(int i=0; i<N ;i++){
            
            for(int j=i; j<N; j++){
                if(i==0)
                    sum.push(arr[j]);
                else
                    sum.push(arr[j]-arr[i-1]);
            }
        }
        
        while(--k > 0)
            sum.pop();
            
        return sum.top();
        
    }
};

// { Driver Code Starts.

int main(){
    
    int T;
    cin>>T;
    while(T--){
        int N,K;
        cin>>N;
        cin>>K;
        vector<int> Arr(N);
        for(int i=0;i<N;i++){
            cin>>Arr[i];
        }
        Solution ob;
        int ans=ob.kthLargest(Arr,N,K);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends