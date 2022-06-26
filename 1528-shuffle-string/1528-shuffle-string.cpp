class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans(s.size(),'s');
        
        int j=0;
        for(auto i:indices)
            ans[i] = s[j++];
        
        return ans;
    }
};