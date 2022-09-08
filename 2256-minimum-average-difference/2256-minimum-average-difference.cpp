class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n =nums.size();
        
        long long sum = 0;
        for(auto& x:nums)
            sum += x;
        
        int idx = 0 ; 
        long long diff = INT_MAX , running = 0; 
        
        for(int i=0;i<n;i++){
            
            running = running + (long long)nums[i];
            
            long minus = (i != n-1) ? (sum-running)/(n-(i+1)) : 0;
            
            long d = abs( running/(i+1) - minus  ) ;
            
            if(d<diff){
                diff = d;
                idx = i;
            }
            //cout<< d << " ";
            
        }
        return idx;
    }
};