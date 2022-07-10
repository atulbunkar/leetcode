class Solution {
public:
    bool canChange(string s, string t) {
        int n = s.size(), m = t.size();
        
        if(n!=m)return false;
        stack<int> st,tt;
        
        for(int i=0;i<m;i++){
            if(s[i] != '_')st.push(s[i]);
            if(t[i] != '_')tt.push(t[i]);
        }
        if(st!=tt)return false;
        
        int L=0,R=0;
        
        for(int i=0;i<m;i++){
            
            if(s[i]=='L'){
                L++;
            }
            if(s[i]=='R'){
                R++;
            }
            
            if(t[i]=='R'){
                R--;
            }
            if(t[i]=='L'){
                L--;
            }
            
            if(L>0 || R<0)return false;
            
            
        }
        
        return true;
    }
    
};