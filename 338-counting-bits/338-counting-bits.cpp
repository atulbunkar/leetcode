class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        
        for(int i=0; i< n+1 ;i++){
            int c = 0;
            int j= i;
            while(j){
           
                if(j&1)
                    c++;
                j = j >> 1;
            }
            ans[i] = c;
        }
        return ans;
           
    }
};