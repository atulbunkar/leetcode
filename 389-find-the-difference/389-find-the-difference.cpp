class Solution {
public:
    char findTheDifference(string s, string t) {
     
        bitset<26> bs;
        bitset<26> bs2;
        
        vector<int> v1(26,0),v2(26,0);
        
        for(char c:t){
            int j = c-'a';
            bs.set(j,1); 
            v1[j]++;
        }
        for(char c:s){
            int j = c-'a';
            bs2.set(j,1);
            v2[j]++;
        }
     
        char a;  
        
        for(int i=0; i <26; i++){
            if(v1[i] != v2[i])
            {
                a = char(i+'a');
            }
        }
        
        return a;
    }
};