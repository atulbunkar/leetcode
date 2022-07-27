class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int g) {
        return h(nums,g) - h(nums,g-1);
    }
    
    int h(vector<int>& nums, int goal){
        int i=0,j=0,ans=0,n=nums.size();
        if(goal <0)return 0;
        while(i<n){
            goal -= nums[i];
            
            if(goal<0){
                
                while(j<i and !nums[j])j++;
                j++;
                goal++;
            }
            ans += i-j+1;
            i++;
        }
        
        return ans;
    }
};