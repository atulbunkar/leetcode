class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n= nums.size(),len;
        vector<int> done(n,0); bool sign, s2;
        
        if(n==1)return false;
            
        
        for(int i=0;i<n; i++){
            
            int j=i;
            sign = nums[i]>0; len = 0;
            
            while(len<n){
                j = j + nums[j];
                if(j>=n)
                    j = j%n;
                else if(j<0)
                    j = n + (j%n);
                
                s2 = nums[j]>0;
                if(sign!=s2){
                    break;
                }
                
                if(j==i and len ==0){
                    break;
                }
                
                if(j==i)return true;
                
                len++;
            }
            
        }
    
    return false;
    }
};