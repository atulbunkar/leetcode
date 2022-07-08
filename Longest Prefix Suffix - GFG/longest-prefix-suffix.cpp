// { Driver Code Starts
//Initial template for C++ 
 
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

//User function template for C++

class Solution{
  public:		
	int lps(string s) {
	    //// Your code goes here
	    int n=s.size();
        vector<int> lps(n);
        int idx=0;  //idx of pattern, assuming
        
        for(int i=1;i <n;){
         
            if(s[i] == s[idx]){
                lps[i] = ++idx;
                i++;
            }
            
            else{
                
                if(idx==0)i++;
                else{
                    idx = lps[idx-1];
                }
                
            }
            
        }
        
	    return lps[n-1];
	   
	    
	}
};

// { Driver Code Starts.

int main() 
{
   

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends