class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        for(int i=0; i<=n;i++){
            int c = 0,j=i;
            
            while(j>0){
                if(j%2 != 0)c++;
                j /= 2;
            }
            ans[i] = c;
            
        }
        
        return ans;
           
    }
};