class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        string s = to_string(n);
        
        int i = s.size()-1;
        int m = i+1;
        
        for(;i>0;i--){
            if(s[i]<s[i-1]){
                m = i;
                s[i-1] = s[i-1]-1;
                //cout<<  s[i-1] << " ";
            }
        }
        
        for(;m<s.size();m++){
            s[m] = '9';
        }
        
        return stoi(s);
    }
};