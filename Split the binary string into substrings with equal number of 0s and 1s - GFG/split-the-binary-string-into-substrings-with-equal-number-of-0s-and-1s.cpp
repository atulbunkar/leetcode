// { Driver Code Starts
/* Driver program to test above function */

#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
    int maxSubStr(string str){
        int ans=0;
        int n= str.size();
        if(n%2)return -1;
        int len =0; int sum=0; int final;
        
        for(int i=0;i<n;i++){
            sum += str[i]=='1' ;
            len ++;
            
            if(len%2)continue;
            
            if(sum == len/2){ 
                ans++;
                len = 0;
                sum = 0;
                final =i;
            }
            
        }
        return final==n-1?ans:-1;
        
    }
};


// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin >> str;
	    Solution ob;
	    int ans = ob.maxSubStr(str);
	    cout << ans<<endl;
	}
	return 0;
}
  // } Driver Code Ends