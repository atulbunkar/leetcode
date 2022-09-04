class Solution {
public:
    bool checkDistances(string s, vector<int>& d) {
        map<char,int> mp;
        int idx = 0;
        
        for(auto x:s){
            if(mp.count(x)){
                if(idx - mp[x] -1 != d[x-'a'])return 0;
            }
            else{
                mp[x] = idx;
            }
            idx++;
        }
        
        return 1;
    }
};