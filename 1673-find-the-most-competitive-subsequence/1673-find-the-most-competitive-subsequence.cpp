class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        vector<int> ans;
        int skip =0;  
        int canskip = nums.size()-k;  //IMP : to know if we will not run out of our nums.
        stack<int> st;
        
        for(int i=0;i<nums.size();i++){
            while(skip< canskip and !ans.empty() and ans.back() > nums[i] ){                                     skip++;                                     
                ans.pop_back();
            }
            
            ans.push_back(nums[i]);
        }

        return vector<int>(ans.begin(),ans.begin()+k);
    }
};