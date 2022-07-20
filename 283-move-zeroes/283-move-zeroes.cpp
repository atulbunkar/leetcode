class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(); int k=0;
        
        for(auto it=nums.begin(); it!=nums.end();){
            if(*it==0){
                nums.erase(it); k++;
            }
            else
                it++;
        }
        
        while(k>0){
            nums.push_back(0);k--;
        }
    }
};