class Solution {
public:
    int countHomogenous(string s) {
        long long ans = 0;
        int j=0;
        int mod =1e9+7;
        long long t=1;
        int n = s.size();
       long long a[26] = {0};
        
        for(int i=0;i<n;i++){
            
            if(s[i+1]==s[i]){
                 t++;
            }
            
            else{
                t =1;
            }
             a[s[i]-'a'] += t;
        }
        
        for(int i=0;i<26;i++){
           // cout<< a[i] << " ";
           // int h = a[i];
            ans +=a[i];
            ans = ans%mod;
        }
        
        return ans;
        
    }
};