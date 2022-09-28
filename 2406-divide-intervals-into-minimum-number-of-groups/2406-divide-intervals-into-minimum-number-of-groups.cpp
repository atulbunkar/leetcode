class Solution {
public:
    int minGroups(vector<vector<int>>& ints) {
        long cnt[1000002] = {0};
        
        for(auto x:ints){
            cnt[x[0]]++;
            cnt[x[1]+1]--;
        }
        
        long ans = 0;
        for(int i=1;i<1000002;i++){
            cnt[i] += cnt[i-1];
            ans = max(ans,cnt[i]);
        }
        return ans;
    }
    
};