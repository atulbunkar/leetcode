class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n=nums.size(); int k=0;
        
        int i=0,j=0;  
        
        while(j<n and i<n){
            
            while(j<n and nums[j]==0)j++;
             if(j==n)break;
            
            nums[i++] = nums[j++];
            
        }
        
        for(i;i<n;i++)
            nums[i] = 0;
        
    }
};