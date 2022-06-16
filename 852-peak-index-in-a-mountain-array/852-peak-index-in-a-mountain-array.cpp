class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        
        int i=0,j = arr.size()-1; int n= arr.size();
        
        while(i<j){
            
            int mid = (i+j)/2;
                
            if(mid ==0){
                i = mid+1;
                continue;
            }
            if(mid == n-1){
                j = mid-1;
                continue;
            }
                
            if(arr[mid] >arr[mid-1] and arr[mid] > arr[mid+1])
                return mid;
            
            else if(arr[mid] > arr[mid-1] and arr[mid] < arr[mid+1])
                i = mid+1;
            else
                j = mid;
            
        }
        return i;
    }
};