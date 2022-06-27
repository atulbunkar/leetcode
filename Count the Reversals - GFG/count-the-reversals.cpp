// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

int countRev (string s);
int main()
{
    int t; cin >> t;
    while (t--)
    {
        string s; cin >> s;
        cout << countRev (s) << '\n';
    }
}

// Contributed By: Pranay Bansal// } Driver Code Ends



int countRev (string s)
{
    if(s.size()%2)return -1;
    stack<char> st;
    
    int n = s.size();
    
    for(int i=0;i<n;i++){
        if(st.empty())st.push(s[i]);
        
        else if(s[i] == st.top() )st.push(s[i]);
        
        else if(st.top() == '}')st.push(s[i]); 
        else st.pop();
    }
    
    int ans=0; char a,b;
    while(!st.empty()){
        a = st.top();
        //cout<<a << " ";
        st.pop();
        b = st.top();
        //cout<<b << " ";
        st.pop();
        if(a==b)ans++;
        else ans +=2;
    }
    
    return ans;
    
}