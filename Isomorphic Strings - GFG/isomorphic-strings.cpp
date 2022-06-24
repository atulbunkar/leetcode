// { Driver Code Starts
// C++ program to check if two strings are isomorphic


#include<bits/stdc++.h>


using namespace std;
#define MAX_CHARS 256

 // } Driver Code Ends
class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        int n=str1.size(), m=str2.size();
        if(n!=m)return false;
        unordered_map<char,char> mp;
        unordered_set<char> done;
        
        for(int i=0;i<n;i++){
            
            if( done.find(str2[i]) != done.end() and mp.find(str1[i]) ==mp.end())return false;
 
            if( done.find(str2[i]) == done.end()  and mp.find(str1[i]) ==mp.end()){
                mp[str1[i]] = str2[i];
                done.insert(str2[i]);  
            }
            
            else if(mp[str1[i]] != str2[i])return false;
         
        }
        
        //for(auto x:mp)cout<<x.first << " "<< x.second ;
        return true; 
    }
};

// { Driver Code Starts.

// Driver program
int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  // } Driver Code Ends