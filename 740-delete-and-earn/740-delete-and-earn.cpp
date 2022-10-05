class Solution {
public:
    vector<int> dp;
    int helper(vector<pair<int,int>> &temp,int i){
        int n = temp.size();
        if(i >= n)
            return 0;
        if(dp[i]!= -1)
            return dp[i];
        int x = temp[i].first*temp[i].second;
        if(i < n-1 && temp[i+1].first == temp[i].first+1)
            return dp[i] = max(x+helper(temp,i+2),helper(temp,i+1));
        return dp[i] = x+helper(temp,i+1);
    }
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto &it : nums)
            mp[it]++;
        vector<pair<int,int>> temp;
        for(auto it : mp){
            temp.push_back({it.first,it.second});
        }
        int n = nums.size();
        dp.resize(n,-1);
        return helper(temp,0);
    }
};