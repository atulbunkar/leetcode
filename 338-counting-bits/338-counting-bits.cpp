class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        for(int i=0;i<=n ;i++){
            int j=i; int ones=0;
            
            while(j){
                
                if(1 & j)ones++;
                j = j>>1;
                
            }
            ans[i] = ones;
            
        }
        
        return ans;
           
    }
};