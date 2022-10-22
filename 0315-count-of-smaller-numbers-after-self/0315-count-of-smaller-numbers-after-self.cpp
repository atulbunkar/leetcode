class Solution {
public:
    vector<int> bit ;
    
    void update(int i,int k){
        int n = 5*1e5+5;
        while(i<n){
            bit[i] += k;
            i += (i&-i) ;
        }
    }
    
    int sum(int i){
        int s = 0;
        while(i>0){
            s += bit[i];
            i -= (i&-i);
        }
        return s;   
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = 5*1e5 + 5;
        int m = 1e4+3 ;
        bit.resize(n);
        vector<int> ans ;
       
        for(int i = nums.size()-1; i>=0; i--){
             
            ans.push_back(sum(nums[i]+m-1)) ;
            update(nums[i]+m,1);   
        }
        
        reverse(ans.begin(),ans.end());
        return ans;
    }
};