class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        
        unordered_map<int, int > mp;
            
        for(auto x:nums){
            mp[x]++;
        }
        
        
        priority_queue<pair<int,int>> mp2;
        
        for(auto x:mp){
            mp2.push({x.second,x.first});
        }
        
        vector<int> ans;
        while(1){
            k--;
            ans.push_back(mp2.top().second);
            mp2.pop();
            if(k<=0)break;
        }
        
        
        
        return ans;
        
    }
};