class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n=nums.size();
        vector<int> left(n),right(n),v;
        
        v.push_back(nums[0]);    left[0] = 0;
        for(int i=1;i<n;i++){   //getting LIS from left for index i.
            
            auto it = lower_bound(v.begin(),v.end(),nums[i]);  
            
            left[i] = it - begin(v) ; // left[i] is the len of LIS with nums[i] at end but 
                                        // does not count nums[i] in length  
                                      // i.e  it - begin(v) gives len -1 at index i.
            if(it == v.end()){         
                v.push_back(nums[i]);   
            }   
            else if(*it >= nums[i]){
                *it = nums[i];
            }
        }
        
        v.clear(); v.push_back(nums[n-1]); right[n-1] = 0;
        
        for(int i=n-2;i>=0;i--){   //getting LIS from left for index i.
            
            auto it = lower_bound(v.begin(),v.end(),nums[i]);  
            
            right[i] = it - begin(v) ; 
                                     
            if(it == v.end()){         
                v.push_back(nums[i]);   
            }   
            else if(*it >= nums[i]){
                *it = nums[i];
            }
        }
        
        int ans = INT_MAX;
        for(int i=1; i<n; i++){
            if(left[i]and right[i])ans = min(ans, n- (left[i]+right[i]+1)) ; //+1 bcoz left[i] and right[i]stores
        }                                           //len till i but not i;
        

        return ans;
    }
};