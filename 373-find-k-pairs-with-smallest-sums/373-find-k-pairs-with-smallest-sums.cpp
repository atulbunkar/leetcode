class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int i=0,j=0;  vector<vector<int>> ans;
        int n1 =nums1.size() , n2= nums2.size(); int k1=0,l=0;
        
        multimap<int , pair<int,int>> mp;
        
        for(int i = 0;i< n1; i++)
            for(j = 0; j<n2; j++){
                int s = nums1[i]+nums2[j];
               
                if(mp.size()<k)
                    mp.insert(make_pair(s,make_pair(nums1[i],nums2[j]))) ;
                else if(s < mp.rbegin()->first){
                    mp.erase(prev(mp.end()));
                    mp.insert(make_pair(s,make_pair(nums1[i],nums2[j]))) ;
                }
                else
                    break;
            }
        
        for(auto it = mp.begin() ; it != mp.end() ; it++){
            if(k-- == 0)break;
            auto x = it->second;
            
            ans.push_back({x.first, x.second});
        }
        
        
        return ans;
    }
};