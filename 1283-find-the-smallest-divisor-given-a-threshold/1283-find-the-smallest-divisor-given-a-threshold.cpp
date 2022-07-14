class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        
        int l = 1;
        int r= 1e6;
        int n =nums.size();
        while(l<=r){
            
            int mid = (l+r)/2;
            int sum=0;
            for(int i=0;i<n;i++){
                sum+=ceil((double)nums[i]/mid);
                if(sum>threshold)break;
            }
            if( sum <= threshold ){
                r = mid -1;
            }
            else{
                l = mid+1;
            }
        }
        return l;
    }
};