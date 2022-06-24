class Solution {
public: //KMP
    string longestPrefix(string s) {
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
        
        return s.substr(0,lps[n-1]);
    }
};