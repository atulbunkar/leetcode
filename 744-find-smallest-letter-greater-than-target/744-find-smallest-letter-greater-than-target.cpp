class Solution {
public:
    char nextGreatestLetter(vector<char>& l, char t) {
        auto it = upper_bound(l.begin(), l.end(),t);
        
        if(it==l.end())return l[0];    
            
        return *it;
    }
};