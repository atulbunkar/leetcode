class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> tt;
        
        for(auto x:t)tt[x]++;
        int cnt = t.size();
        
        int n  = s.size(); string ans = "";
        int j =0;
        
        for(int i=0;i<n;i++){
            
            if(tt[s[i]]-- >0)cnt-- ;
            
            while(cnt==0){
                
                if(ans.empty() || ans.size() > i-j+1){
                    ans= s.substr(j,i-j+1);
                    
                }
                
                if(tt[s[j++]]++==0 )cnt++;
                
            }
            
        }
        
        return ans;
    }
};