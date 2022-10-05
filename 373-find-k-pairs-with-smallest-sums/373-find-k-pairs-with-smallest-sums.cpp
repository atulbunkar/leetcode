class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<>> pq;
        for(int i = 0 ; i < nums1.size(); i++){
            pq.push({nums1[i]+nums2[0],{i,0}});
        }
        int n = nums2.size();
        vector<vector<int>> ans;
        while(k-- && !pq.empty()){
            auto x = pq.top();
            pq.pop();
            int i = x.second.first;
            int j = x.second.second;
            ans.push_back({nums1[i],nums2[j]});
            j++;
            if(j < n)
                pq.push({nums1[i]+nums2[j],{i,j}});
            
        }
        return ans;
    }
};