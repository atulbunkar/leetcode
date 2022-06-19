class Solution {
public:
    int longestSubsequence(string s, int k) {
         int n= s.size(); int ans=-1,p=0;
        int t =0;

        for(int j=n-1;j>=0;j--){         
            if(s[j]-'0' == 1 ){
                if(p>30)continue;
                else t += pow(2,p);
            }

            if(t>k){t-= pow(2,p); }
            else p++;
        } 
 
        return p;
    }

};