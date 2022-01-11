class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> c ;
        int len = nums.size()/2;
        
        
        for(auto x: nums){
            c[x]++;
        }
        
        for(auto x: c){
            if(x.second > len)return x.first;
        }
        
        return 0;
    }
};