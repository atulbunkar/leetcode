// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int mem[101][101];
    
    int editDistance(string s, string t) {
        memset(mem,-1,sizeof(mem));
        return dp(0,0,s,t);
        
    }
    
    int dp(int i,int j ,string& s, string& t ){
        
        if(i>=s.size() and j>=t.size())return 0;
        
        if(i>=s.size())return t.size()-j;
        if(j>=t.size())return s.size()-i;
        
        if(mem[i][j] != -1)return mem[i][j];
        
        if(s[i]==t[j])return mem[i][j] =dp(i+1,j+1,s,t);
        
        else{
            return mem[i][j] =min(dp(i+1,j+1,s,t), min(dp(i+1,j,s,t) ,dp(i,j+1,s,t)) )+1; 
        }
        
    }
    
};

// { Driver Code Starts.
int main() {
    int T;
    cin >> T;
    while (T--) {
        string s, t;
        cin >> s >> t;
        Solution ob;
        int ans = ob.editDistance(s, t);
        cout << ans << "\n";
    }
    return 0;
}
  // } Driver Code Ends