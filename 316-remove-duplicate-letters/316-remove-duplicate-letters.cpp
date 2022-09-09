class Solution {
public:
    string removeDuplicateLetters(string s) {
        map<char,int> cnt;
        for(auto x:s)cnt[x]++;
        
        string ans = "";
        vector<int> onstk(26,0);
        
        int n = s.size();
        
        for(int i=0;i<n;i++){
            
            if(onstk[s[i]-'a']==1){
                cnt[s[i]]--;
                continue;
            }
            
            while(!ans.empty()){
                
                if(ans.back() > s[i] and cnt[ans.back()]>0){
                   // cnt[sc.top()]--;
                    onstk[ans.back()-'a'] = 0;
                    //sc.pop();
                    ans.pop_back();
                }
                else
                    break;
                
            }
            ans += s[i];
            cnt[s[i]]--;
            onstk[s[i]-'a'] = 1;
        }
        
       
      //  reverse(ans.begin(),ans.end());
        return ans;
    }
};