class Solution {
public:
     
    vector<string> letterCasePermutation(string s) {
        vector<string> ans;
        
        dfs(0,s,ans);
        return ans;
    }
    
    void dfs(int x , string& s  ,vector<string>& ans){
        
        if(x>=s.size()){
            ans.push_back(s);
            return;
        }
    
        int i = x;
        dfs(i+1,s,ans);
 
        if(isdigit(s[i]))return ;

        if(islower(s[i]))s[i] = toupper(s[i]);
        else s[i] = tolower(s[i]);

        dfs(i+1,s,ans);

        
    }
};