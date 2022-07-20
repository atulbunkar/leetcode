class Solution {
public:
    int wateringPlants(vector<int>& p, int c) {
        
        int i=0;
        int n=p.size(); 
        int k=c; int step=0; 
        
        for(;i<n;i++){
            
            k -= p[i];
            step++;
            
            if(i<n-1 and p[i+1] > k ){
                k=c;
                step += 2*(i+1);
            }
             
        }
        return step;
    }
};