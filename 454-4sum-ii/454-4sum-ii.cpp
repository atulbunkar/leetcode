class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int> sums;
        int n = nums1.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int t = nums1[i]+nums2[j];
                sums[t]++;
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int t = nums3[i]+nums4[j];
                t = -1*t;
                if(sums.count(t))
                    ans += sums[t];
            }
        }
        return ans;
    }
};