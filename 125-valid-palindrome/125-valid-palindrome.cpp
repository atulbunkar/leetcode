class Solution {
public:
    bool isPalindrome(string s) {
        if(s.empty())return true;
        
        int i =0, j = s.size()-1;
        
        while(i<j){
            while(i<j and isalnum(s[i]) == false){
               // cout << s[i];
                i++;
            }
            while(i<j and isalnum(s[j]) == false){
                j--; 
            }
            if(toupper(s[i]) != toupper(s[j]))return false;
            i++; j--;
            
        }
        return true;
    }
};