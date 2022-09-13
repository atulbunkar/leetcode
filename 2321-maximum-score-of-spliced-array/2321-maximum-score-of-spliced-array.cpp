class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        
        long long s1=0,s2=0;
        for(int i=0;i<n;i++){s1 += nums1[i]; s2 += nums2[i];}
        
       // if(s2>s1)swap(nums1,nums2);
        
        vector<int> diff(n),diff2(n);
        
        for(int i=0;i<n;i++){
            diff[i] = nums2[i] - nums1[i] ;
            diff2[i] = nums1[i] - nums2[i];
        }
        
        long sum =0,ans=0;
        
        for(int i=0;i<n;i++){
            
            sum  += diff[i];
           
            if(sum <0)sum =0;
            ans = max(ans,sum);
            
        }
        
         sum =0; long ans2=0;
        
        for(int i=0;i<n;i++){
            
            sum  += diff2[i];
           
            if(sum <0)sum =0;
            ans2 = max(ans2,sum);
            
        }
        
        return max(ans+s1 , ans2+s2);
    }
};