class Solution {
public:
    static bool cmp(const vector<int>&a,const vector<int>&b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& p) {
        
        sort(p.begin(),p.end(),cmp);
        
        int ans=1; int end = p[0][1];
        int n=p.size();
        
        for(int i=1;i<n;i++){
            if(p[i][0] > end){
                ans++;
                end = p[i][1];
            }
        }
        
        return ans;
    }
};