class Solution {
public:
    int ret=0;  vector<vector<int>> mem;
    
    int numberOfArithmeticSlices(vector<int>& nums) {
        
        int n=nums.size(); int curr=0;
         mem.resize(n+1,vector<int>(n+1,-1));
        
        for(int i=0;i<n-2;i++){
            for(int j=i+2;j<n;j++){
                if(isarth(i,j,nums))curr++;
            }
        }
        return curr;
    }
   
    
    bool isarth(int i,int j,vector<int>& nums){
        if(i==j)return true;
        
        if(mem[i][j] != -1)return mem[i][j];
        
        if(nums[i+1]-nums[i] == nums[j]-nums[j-1])return mem[i][j]= isarth(i+1,j,nums) and isarth(i,j-1,nums);
        
        return mem[i][j] = false;
        
    }
   
    
};