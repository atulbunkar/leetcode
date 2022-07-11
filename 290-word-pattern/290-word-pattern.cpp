class Solution {
public:
    vector<string> split (string s, string delimiter) {
    size_t pos_start = 0, pos_end, delim_len = delimiter.length();
    string token;
    vector<string> res;

    while ((pos_end = s.find (delimiter, pos_start)) != string::npos) {
        token = s.substr (pos_start, pos_end - pos_start);
        pos_start = pos_end + delim_len;
        res.push_back (token);
    }

    res.push_back (s.substr (pos_start));
    return res;
}
    
    bool wordPattern(string pattern, string s) {
        vector<string>words = split(s," ");
        set<string>st;
        map<char,string>mp;
        int n = pattern.size();
        if(words.size() != n)return 0;
        for(int i =0;i<n;i++){
            if(mp.count(pattern[i])) {
                if(mp[pattern[i]] != words[i])
                    return 0;
            }
            else{
                if( st.find(words[i])!=st.end() )
                    return 0;
                
                mp[pattern[i]] = words[i];
                st.insert(words[i]);
            }
        }
        
        return 1;
    }
};