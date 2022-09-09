class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> cnt;
        for(auto x:s)cnt[x]++;
        
        stack<char> sc;
        vector<int> onstk(26,0);
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            
            if(onstk[s[i]-'a']==1){
                cnt[s[i]]--;
                continue;
            }
            
            while(!sc.empty()){
                
                if(sc.top() > s[i] and cnt[sc.top()]>0){
                   // cnt[sc.top()]--;
                    onstk[sc.top()-'a'] = 0;
                    sc.pop();
                }
                else
                    break;
                
            }
            sc.push(s[i]);
            cnt[s[i]]--;
            onstk[s[i]-'a'] = 1;
        }
        
        string ans = "";
        while(!sc.empty()){
            ans += sc.top();
            sc.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};