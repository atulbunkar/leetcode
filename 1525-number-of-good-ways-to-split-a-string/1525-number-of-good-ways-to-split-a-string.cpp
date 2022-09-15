class Solution {
public:
    int numSplits(string s) {
        map<char,int> samne,piche;
        
        for(auto x:s)piche[x]++;
        int ans = 0;
        for(auto x:s){
            
            samne[x]++;
            
            if(piche[x] == 1)piche.erase(x);
            else piche[x]--;
            
            if(samne.size() == piche.size())ans++;
            
        }
        
        return ans;
    }
};