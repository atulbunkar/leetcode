class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n =nums.size(); int mx = 1;
        vector<int> lis(n,1) , count(n,1);
        
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                
                if(nums[j] < nums[i]){
                    if(lis[j]+1 > lis[i]){ //new bigger lis
                        lis[i] = lis[j]+1 ;
                        count[i] = count[j];
                        
                    }
                    else if(lis[j]+1 == lis[i]){ //new lis of same length
                        count[i] += count[j];
                    }  
                }
            }
            mx = max(mx,lis[i]);
        }
        
        
        int ans =0;
        for(int i=0;i<n;i++)
            if(lis[i] == mx)ans += count[i];
     
        
        return ans;
        
    }
    

};