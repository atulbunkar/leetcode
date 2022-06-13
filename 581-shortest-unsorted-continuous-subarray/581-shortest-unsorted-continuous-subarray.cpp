class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        vector<int> n = nums;
        
        sort(n.begin(),n.end());
        
        int i =0 , j = n.size()-1;
        
        while(i< n.size()){
            if(n[i] == nums[i])
                i++;
            else
                break;
        }
        
        while(j>0){
            if(n[j] == nums[j])j--;
            else break;
        }
        
        
        return j-i+1 > 0 ? j-i+1 :0;
        
    }
};