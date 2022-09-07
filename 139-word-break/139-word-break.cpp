class Solution {
public:
    //bool flag= false;
    int mem[301];
    bool wordBreak(string s, vector<string>& wd) {
        memset(mem,-1,sizeof(mem));
      unordered_set<string> st;
        
      for(auto& x:wd){
          st.insert(x);
      }
        
     return rec(0,s.size(),s,st);
        
    }
    
    bool rec(int i,int j,string& s, unordered_set<string>& st){
        
        if(i>=j)return 1;
        if(mem[i] !=-1)return mem[i];
        
        string t = "" ;
        bool ans = false;
        
        for(int k=i;k<j;k++){
            t += s[k];
            if(st.count(t)){
                ans |= rec(k+1,j,s,st); 
               // cout<< i << " " << ans;
            }
        }
        return mem[i] = ans;
        
    }
    
   
    
};