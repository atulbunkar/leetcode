#define pii pair<int,int>
class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        //priority_queue<pii, vector<pii> , greater<pii>> pq2;
        
        int n = nums1.size();
        
        multiset <int> n1(nums1.begin() , nums1.end());
    
        for(int i=0;i<n;i++){
            
            auto ub = n1.upper_bound(nums2[i]);
            
            if(ub==n1.end()){
            
                nums1[i] = *(n1.begin());
                n1.erase(n1.begin());   
            }
             else{
                 
                 nums1[i] = *ub;
                 n1.erase(ub);
                 
             }
            
            
        }
        
       
        return nums1;
        
    }
};