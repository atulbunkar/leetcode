class Solution {
public:
    int numberOfSubstrings(string s) {
        int i=0,j=0;
        int n =s.size();
        
        vector<int> v(3,0); int ans = 0;
        while(i<n){
            
            v[s[i]-'a']++;
            
            while(v[0] and v[1] and v[2]){
                ans += n-i;
                
                v[s[j++]-'a']--;    
            
            }
      
            i++;
        }
        return ans;
    }
};