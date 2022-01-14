class Solution {
public:
    void sortColors(vector<int>& nums) {
        int c[3] = {0};
        
       
        for(int i = 0 ; i< nums.size() ; i++){
            c[nums[i]]++;
        }
        
        int i =0;
        while(c[0]--){
            nums[i++] =0;
        }
        while(c[1]--){
            nums[i++] =1;
        }
        while(c[2]--){
            nums[i++] =2;
        }

    }
};