class Solution {
public:
    int characterReplacement(string s, int k) {
       
        int n =s.size() , ans= 1; set<char> st;
        for(auto x:s)st.insert(x);
        
        for(auto c:st){
            int j=0; int k1 = k;
            for(int i=0; i<n;i++){

                if(s[i] != c)k1--;

                while(k1<0){
                    if(s[j]!=c)k1++;
                    
                    j++;
                }
             
                ans = max(ans, i-j+1);
            }
        }
        
        return ans;
    }
};