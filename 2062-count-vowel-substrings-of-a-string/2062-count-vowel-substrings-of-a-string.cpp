class Solution {
public:
    int countVowelSubstrings(string w) {
        int ans=0;
        
        int n = w.size(); map<char,int> mp; int j=0;
        
        set<char> s = {'a','e','i','o','u'}; int i=0;
        
        for(;i<n;i++){
            
            if(find(s.begin(),s.end(),w[i]) != s.end() )mp[w[i]]++;
            else{
                j = i+1;
                mp.clear();
                continue;
            }
            
            while(mp.size() ==5){
                ans++;
                int k = i+1;
                while(k<n and find(s.begin(),s.end(),w[k]) != s.end()) {ans++ ; k++;}
                
                if(mp[w[j]]-- == 1)mp.erase(w[j]); j++;
                
            }
            
        }
        
        while(mp.size() ==5){
            ans++;

            if(mp[w[j]]-- == 1)mp.erase(w[j]); j++;
        }
        
        
        
        
        return ans;
    }
};