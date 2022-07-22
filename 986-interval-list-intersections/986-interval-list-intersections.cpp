class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        //make to 2 list in 1 and sort it by start pos
        vector<vector<int>> ans;
        for(auto &x :s)
            f.push_back(x);
        
        sort(f.begin(),f.end());
        int n =f.size();
        for(int i=0;i<n;i++){
            int st = f[i][0], end = f[i][1];
            int j=i+1;
            while(j<n and f[j][0] <= end){

                int e = min(end,f[j][1]) ;
                ans.push_back({f[j][0],e});
                j++;
            }
        }
        
         return ans;
        
    }
};