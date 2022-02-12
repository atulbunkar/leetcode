class Solution {
public:
    string smallestSubsequence(string s) {
        vector<int> c(26,0);  string ans = "";
        vector<int> done(26,0);
        
        for(auto x:s)
            c[x-'a']++;
        
        for(auto x:s){
            c[x-'a']--;
            
            if(done[x-'a']>0 )continue; done[x-'a']++;
                
            while(!ans.empty() and ans.back() > x and c[ans.back()-'a'] >0 ){
         
                done[ans.back()-'a']=0;
                ans.pop_back();
            }
                
            ans.push_back(x);
        
        
        }
        return ans;
    }
    
    
};