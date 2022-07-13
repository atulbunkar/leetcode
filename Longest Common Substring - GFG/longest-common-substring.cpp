// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{
    public:
    int mem[1001][1001];
    int longestCommonSubstr (string s1, string s2, int n, int m)
    {
        memset(mem,-1,sizeof(mem));
       if(m>n){swap(s1,s2); swap(m,n);} // 2nd will be small
       int ans= 0;
    
       for(int i=0;i<n;i++){
           for(int j=0;j<n;j++)
                ans = max(ans, dp(i,j,s1,s2,n,m));
       }
       return ans;
       
       
    }
    
    int dp(int i,int j,string& s1, string& s2, int n, int m){
        if(i>=n || j>=m)return 0;
        
        if(mem[i][j]!=-1)return mem[i][j];
        
        if(s1[i]==s2[j]){
            return mem[i][j] = 1+dp(i+1,j+1,s1,s2,n,m);
        }
        else{
            return mem[i][j] = 0;
        }
        
    }
    
    
};

// { Driver Code Starts.

int main()
{
    int t; cin >> t;
    while (t--)
    {
        int n, m; cin >> n >> m;
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr (s1, s2, n, m) << endl;
    }
}
// Contributed By: Pranay Bansal
  // } Driver Code Ends