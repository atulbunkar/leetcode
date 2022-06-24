class Solution {
public:
    bool rotateString(string s, string g) {
       
        int n=s.size() ,m= g.size();
        
        if(n!=m)return false;
        
        char x = g[0]; int i=0,idx;
        
        while(n--){
            if(s==g)return true;

            g =  g.back() + g  ; 
            g.pop_back();
            
        }
        
        
        return false;
    
    }
    
};