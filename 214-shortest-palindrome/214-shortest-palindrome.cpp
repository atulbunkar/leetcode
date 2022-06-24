
class Solution {
public:
    vector<string> st;
    string shortestPalindrome(string s) {
        int m = s.size();
        
        string t = s + '5'   ;
        reverse(s.begin(),s.end());
        t += s; 
        
        int n = t.size();
        vector<int> lps(n);
        
        int idx=0;
        for(int i=1;i<n; ){
            if(t[i]==t[idx]){
                lps[i] = ++idx;
                i++;
            }
            else{
                if(idx==0)i++;
                else
                    idx = lps[idx-1];  
            }  
            
        }
        int add = m - lps[n-1] ;
        
      //  for(auto x:lps)cout<<x<< " ";
        
        string ans = s.substr(0,add) ;
        reverse(s.begin(),s.end());
        ans += s;
        
        return ans;
        
    }
    

};
    
    
