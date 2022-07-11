class Solution {
public:
    bool repeatedSubstringPattern(string t) {
        int n = t.size();  vector<int> lps(n);
       
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
        
   
    
        return  lps[n-1] && (lps[n-1]%(n-lps[n-1])==0);
;
    }
};