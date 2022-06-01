class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
         vector<vector<int>> ans;
        vector<int> t;
        bt(k,n,1,ans,t,0);
        
        return ans;
    }
    
    void bt(int k ,int n, int x, vector<vector<int>>& ans,  vector<int>& t, int sum){
        if(t.size()==k){
            if(sum == n){
                ans.emplace_back(t);
                return;
            }
            else{
                return;
            }
        }
        
        for(int i = x;i <= 9;i++){
            t.emplace_back(i); sum+= i;
            bt(k,n,i+1,ans,t,sum);
            t.pop_back(); sum -= i;
        }
        
        
    }
};