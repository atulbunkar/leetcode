class Solution {
public:
    int totalFruit(vector<int>& f) {
        int ans = 1; int n = f.size(); int j=0, i =1;
        
        vector<int> curr(2,-1);  curr[0] = f[0];
        
        for(i=1; i<n; i++){
            
            if(f[i] == curr[0] || f[i] == curr[1] ){
                 ans = max(ans , i-j+1);
                //cout<< i << " " << j << " " << ans<< endl;
            }
            
            else{
                if(curr[1] == -1){
                    curr[1] = f[i]; ans = max(ans , i-j+1);  continue;
                }
                
                for(j=i-1 ; f[j-1] == f[i-1] and j>1 ; j--);
                
                curr[0] = f[i-1];
                curr[1] = f[i];
            }
            
        }
        
        //cout<< i << " " << j << " "<< endl;
        return ans;   
        
    }
};