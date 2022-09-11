class Solution {
public:
    int characterReplacement(string s, int k) {
        int K = k;
        int n = s.size();
         int ans = -1;
        set<char> cc;
        for(auto x:s)cc.insert(x);
        
        for(auto c:cc){
            int i=0,j=0; k= K;
            while(i<n){
               
                if(s[i] != c)k--; 
              
                while(k<0){
                    if(s[j]!=c)k++;
                    j++;
                }
                
                ans = max(ans, i-j+1);
               
                i++;
            }
                
        }
        return ans;
    }   
};