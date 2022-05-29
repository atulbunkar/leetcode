class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> t;
         if(s.empty()) return ans;
        all(s,ans,t,0);
        
        return ans;
        
    }
    
    
    void all(string& s , vector<vector<string>>& ans , vector<string>& t ,int x){
        if(x>=s.size()){
            ans.emplace_back(t);
            return;
        }    
        string ss;
        
        for(int i=x; i< s.size() ; i++){
            ss = s.substr(x,i-x+1);
            
            if(ispal(ss)){
                t.push_back(ss);
                all(s,ans,t,i+1);
                t.pop_back();
            }
            
            
        }
        
        return;
        
    }
    
    bool ispal(string sk){
        int i = 0, j = sk.size()-1 ;
        
        while(i<=j){
            if(sk[i++] != sk[j--])return false;
        }
        return true;
    }
    
};