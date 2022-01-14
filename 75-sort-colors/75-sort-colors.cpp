class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c[3] = {0};
        
       
        for(int i = 0 ; i< nums.size() ; i++){
            c[nums[i]]++;
        }
        
        int i =0;
        
        for(int j = 0; j< 3;j++){
            while(c[j]--){
                nums[i++] =j;
            }
        }

    }
};