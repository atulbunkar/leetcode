class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    
        int i=m-1, j=n-1;
        int zeroptr = m+n-1;
        
        while(i >=0 and j>=0){
            if(nums2[j] < nums1[i]){
                nums1[zeroptr--] = nums1[i--]; 
            }
            else{
                nums1[zeroptr] = nums2[j];
                j--; zeroptr--;
            }
            
        }
        
        while(j>=0){
            nums1[zeroptr--] = nums2[j--];
        }
       
        
    }
};