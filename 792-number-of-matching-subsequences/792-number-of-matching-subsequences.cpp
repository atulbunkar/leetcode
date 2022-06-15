class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& w) {
        int ans= 0; unordered_map<char,vector<int>> mp;
        
        for(int i=0;i < s.size() ; i++){
            mp[s[i]-'a'].push_back(i);
        }
        
        for(auto x:w){
            int idx = -1; bool found = true;
            
            for(auto c:x){
                auto z = upper_bound(mp[c-'a'].begin(), mp[c-'a'].end() , idx)    ;
                if(z == mp[c-'a'].end()){found = false ; break;}
                else
                    idx = *z;
            }
            
            if(found)ans++;
            
        }
        
        return ans;
        
    }
};