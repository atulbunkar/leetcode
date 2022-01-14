class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefprod, suffprod;
        int temp =1 , t2 =1;
        
        for(int i = 0 ; i < nums.size() ; i++){
            temp = temp*nums[i];
            prefprod.push_back(temp);
            
            t2 = t2*nums[nums.size()-i-1];
            suffprod.push_back(t2);
            
        }
        reverse(suffprod.begin(), suffprod.end());
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(i==0){
                nums[i] = suffprod[i+1];
            }
            else if(i==nums.size()-1)
                nums[i] = prefprod[i-1];
            else
                nums[i] = prefprod[i-1] * suffprod[i+1]; 
        }
        return nums;
    }
};