class Solution {
public:
   
    int lengthOfLastWord(string s) {
        int ret = 0;
        bool has = false;
        int i = s.size()-1;
    
        while(s[i] == ' ' )i--;
        
        while( i>-1 and s[i] != ' ' ){ret++ ; i--; }
    
        return ret ;
    
    }
};