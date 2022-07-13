// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &m, int r, int c){
        int low=m[0][0], high=m[0][c-1];
        
        for(int i=0;i<r;i++){
            low =  min(low, m[i][0]);
            high = max(high,m[i][c-1]);
        }
        int need = (r*c)/2;
        
        while(low<=high){
            
            int mid = (low+high)/2;
            int prev=0;
            for(int i=0;i<r;i++){
               auto it = upper_bound(m[i].begin(),m[i].end(),mid); 
               prev += it - m[i].begin();
            }
            
            if(prev>need){
             high = mid-1;
            }
            else{
                low = mid+1;
            }
    
        }
        return low;
            
            
    }
        
      
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  // } Driver Code Ends