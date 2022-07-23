class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        
        int m= f.size();
        
        if(m==1){
            if(n==0)return 1;
            if(n<=1 and f[0]==0)return 1;
            return 0;
        }
        
        for(int i=0; i<m-1; i++){
                
            if(i==0){
                if(!f[i] and !f[i+1]){
                    f[i] = 1; n--;
                }
            }
            
            else if(!f[i-1] and !f[i] and !f[i+1])
            {
                f[i] = 1;
                n--;
            }
            
        }
        
        if(f[m-2]==0 and f[m-1]==0)n--;
        
        return n<=0;
        
    }
};