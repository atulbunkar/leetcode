class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m= s2.size();
        
        if(m<n)return false;
        int len;
        
        vector<int> s(26,0) ;
        for(int i=0;i<n;i++)s[s1[i]-'a']++;
        
        vector<int> ss=s;
        
        for(int i=0;i<m;i++){
            
            if(ss[s2[i]-'a'] ==0)continue;
            len = 0;
            
            int j=i;
            while(j<m and ss[s2[j]-'a'] > 0){
                ss[s2[j]-'a']--;
                len++;
                j++;
            }
            if(len == n)return true;
            ss = s;

        }
        return false;
    }
};