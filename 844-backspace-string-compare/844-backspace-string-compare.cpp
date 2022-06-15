class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int n= s.size(), m= t.size();
        
        string s1 = "";
        
        for(auto x:s)
        {
            if(!s1.empty() and x == '#')s1.pop_back();
            
            else if(x != '#')s1 += x;  
                
        }
        s = s1;
        s1 = "";
        for(auto x:t)
        {
            if(!s1.empty() and x == '#')s1.pop_back();
            
            else if(x != '#')s1 += x;  
                
        }
        
        return s==s1;
    }
};