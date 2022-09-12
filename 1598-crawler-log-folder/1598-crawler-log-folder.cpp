class Solution {
public:
    int minOperations(vector<string>& logs) {
        int ans = 0;
        
        for(auto &x:logs){
            if(x=="../"){
                ans = max(0,ans-1);
            }
            else if(x != "./")ans++;
        }
        
        return ans;
    }
};