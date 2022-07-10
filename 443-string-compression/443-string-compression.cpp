class Solution {
public:
    int compress(vector<char>& chars) {
        int i=0,j=0;
        int n = chars.size(); string ss;
        
        if(n==1)return 1;
        
        for(int i=0;i<n;){
            int len=1;
            
            while(i<n-1 and chars[i+1]==chars[i]){
                len++; i++;
            }
            chars[j++] = chars[i];
            
            if(len>1){
                ss = to_string(len);
                for(auto x:ss)chars[j++] = x;
            }
            i++;
        }
       
        return j;
    }
};