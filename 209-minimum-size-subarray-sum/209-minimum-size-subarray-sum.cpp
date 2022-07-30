class Solution {
public:
    int minSubArrayLen(int t, vector<int>& nums) {
        int ans = nums.size()+1;
        int n = ans-1;
        
        int i=0,j=0; int s=0;
        
        while(i<n){
            s += nums[i];
            
            while(j<i  and s>=t){      
                ans = min(ans,i-j+1);

                s -= nums[j++];

            }
            
            if(s>=t)ans = min(ans,i-j+1);
            

            i++;
        }
        
        return ans==n+1 ? 0:ans ;
    }
};