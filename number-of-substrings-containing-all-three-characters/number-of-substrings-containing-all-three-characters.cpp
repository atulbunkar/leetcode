class Solution {
public:
    int numberOfSubstrings(string s) {
        int count=0 , c1 =0;
        
        vector<int> let(3,0);
        
        int j =0;
        
        int n = s.size(); bool flag;
        
        for(int i=0 ; i < n ; i++){
            
            let[s[i]-'a']++;
     
            while(let[0] and let[1] and let[2]){
                
                let[s[j++]-'a']--;
                c1++;
                flag = true;
            }
           
            count += c1 ;  
        }
    return count;
    }
};