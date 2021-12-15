class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> ans;
        
        ans.push_back({1});
        if(n==1)return ans;
        
        for(int i=1; i< n; i++){
            vector<int> temp(i+1,1);
            for(int j=0; j<=i ;j++){
                if(j==0 || j==i)continue;
                
                temp[j] = ans[ans.size()-1][j-1] + ans[ans.size()-1][j];
                
            }
            ans.push_back(temp);
        
        }
        return ans;
    }
};