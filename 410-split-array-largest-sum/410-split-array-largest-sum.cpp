class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int min=1,max=1e9;  
        int ans = -1;
        int N = nums.size();
        if(m>=N)return *max_element(nums.begin(),nums.end());
        
        while(min<=max){
            int mid = (max+min)/2; // mid is curr 
            int run =0; int k=m; bool f = false; int p=0;
           // cout<< mid << "-> ";
            for(int i=0;i<N;i++){
                
                if(run+nums[i] > mid ){ //check if adding curr num will overflow mid
                    if(k==1 || nums[i]>mid){f = true;break;}
                    else k--;
                    run = nums[i]; //tricky part , set to curr num after partition
                }
                else                //only run sum when no partition
                    run += nums[i];
            }    
            //cout << f<< " ";
            if(f){
                min = mid+1; 
               
            }
            else {
                ans = mid;
                max = mid-1;
            }
        }
        return ans;
    }
        
   
};