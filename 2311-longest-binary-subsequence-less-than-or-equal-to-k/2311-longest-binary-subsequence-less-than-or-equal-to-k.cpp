class Solution {
public:
    int longestSubsequence(string s, int k) {
         int n= s.size(); int ans=-1,p;
        int t =0;
        
        for(int i=n-1;i>=0;i--){
            p=0; t=0;
            for(int j=i;j>=0;j--){         
                if(s[j]-'0' == 1 ){
                    if(p>30)continue;
                    else t += pow(2,p);
                }
          
                if(t>k){t-= pow(2,p); }
                else p++;
            } 
            ans = max(ans,p);      
        }   
        return ans;
    }

};