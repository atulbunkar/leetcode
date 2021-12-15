class Solution {
public:
    bool wordBreak(string s, vector<string>& wd) {
        vector<bool> dp(s.size()+1);
        dp[0] = true;
        
        for(int i = 1; i <= s.size(); i++){
            
            for(int j = 0 ; j<i ; j++){
                if(dp[j] and ( find(wd.begin(), wd.end() , s.substr(j,i-j) ) != wd.end() ) ){
                    dp[i] = true;
                    break;
                }
                
            }
        }
        return dp.back();

    }
};