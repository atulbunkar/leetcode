class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i=0,j=0;
        int n=nums.size();
        
        int ans=0 , t=0 ;
        while(i<n){
            
            if(!nums[i])k--;
           
            if(k<0){
               
                while(j<i and nums[j])j++;
                j++;
                k++;
            }
            
            ans = max(ans,i-j+1);
            
            i++;
        }
        
        return ans;
    }
};