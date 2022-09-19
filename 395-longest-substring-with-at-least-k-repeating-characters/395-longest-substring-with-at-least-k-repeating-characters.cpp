class Solution {
public:
    int longestSubstring(string s, int k) {
       
        return longestSubstring(s,k,0,s.size()-1);
        
    }
    
    int longestSubstring(string s, int k,int i, int l){
        int j =i;

        if(i>l)return 0;
       // cout<< i;
        
        vector<int> fr(26,0);

        for(int j=i;j<=l;j++){
            fr[s[j]-'a']++;
        }
        
        for(j=i;j<=l;j++){
            if(fr[s[j] -'a'] <k )break;
        }
        if(j==l+1)return l-i+1;
        
        
        return max(longestSubstring(s,k,i,j-1) , longestSubstring(s,k,j+1,l)) ;
    }
};