class Solution {
public:
    int maxConsecutiveAnswers(string nn, int k) {
        
        int ans = 0; 
        int n =nn.size(); vector<char> a = {'T','F'};
        
        for(int o=0;o<2;o++){
            char g = a[o]; int i=0,j=0; int kk=k;
            
            while(i<n){
                
                if(nn[i] != g)kk--;
                
                if(kk<0){
                    if(nn[j]!=g)kk++;
                    j++;
                }
                ans = max(ans, i-j+1);
                i++;       
            }
        }
        
        return ans;
    }
};