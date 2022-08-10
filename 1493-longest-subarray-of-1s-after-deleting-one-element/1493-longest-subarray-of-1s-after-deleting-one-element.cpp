class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int k=1; int n =nums.size();
        int i=0,j=0; int ans = 0;
        for(;i<n ;i++){
            if(nums[i]==0)k--;
            
            while(k<0 and j<=i){
               // cout<< j << " " << i <<endl;
                if(nums[j]==0)k++;
                j++;
            }
            //cout<< i-j << " ";
            ans = max(ans,i-j);
        }
        
        return ans==n?n-1:ans;
    }
};