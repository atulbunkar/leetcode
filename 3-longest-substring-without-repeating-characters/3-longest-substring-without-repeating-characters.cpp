class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int a=1;
        vector<int> rep(256,0) ;
        if(s.size()==0 || s.size()==1)return s.size();
        
        int f=0; int ans = 1;
        
        for(int i=0 ; i < s.size() ; i++){
            
            if(rep[s[i]]==0)
                rep[s[i]] += 1;
            
            else{
                while(s[f] != s[i]){
                    rep[s[f]] -=1;
                    f++;
                }
                f++;
            }
            
            ans = max(ans,i-f+1);
            
            
        }
      
        return ans;
    }
};