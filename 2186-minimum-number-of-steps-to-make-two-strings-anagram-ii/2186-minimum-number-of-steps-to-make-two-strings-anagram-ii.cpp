class Solution { //just submit
public:
    int minSteps(string s, string t) {
        int n = s.size()+t.size();
        vector<int> cnt(26,0);
        
        for(auto x:s)cnt[x-'a']++;
        for(auto x:t)cnt[x-'a']--;
        
        int diff = 0;
        for(auto x:cnt)diff += abs(x);

        
        return diff;
    }
};