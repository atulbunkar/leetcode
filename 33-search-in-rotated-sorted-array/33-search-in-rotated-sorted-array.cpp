class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n =nums.size() ;
        int st = 0,start = 0 ,l = n-1, last= n-1;
        int pos;
         
        if(n==1)return target == nums[0]?0:-1;
        
        if(nums[start] > nums[last]){
            
            while(start <= last){
                int mid = (start+last)/2;

                if(nums[mid+1] < nums[mid]){
                    pos = mid+1;
                    break;
                }

                else{
                    if(nums[st] > nums[mid])last = mid;
                    else
                        start = mid+1;
                }

            }  

            if(nums[st] > target)
            {
                start = pos;
                last = l;
            }
            else {
                start = 0;
                last = pos-1;
            }
        }

        
        while(start <= last){
            int mid = (start+last)/2;
            
            if(nums[mid] == target)return mid;
            
            if(nums[mid] < target ){
                start = mid+1 ;

            }
            else{
                last = mid-1;
            }
            
        }
       
        
        return -1;
    }
};