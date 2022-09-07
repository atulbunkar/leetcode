#define pii pair<int,int> 
class Solution {
public:
    long long minSumSquareDiff(vector<int>& n1, vector<int>& n2, int k1, int k2) {
        
        vector<pii> v; int n = n1.size();
        
        long long ans = 0;
        int k = k1+k2;
        
       // sort(v.begin(),v.end(), [](pii&a ,pii&b){ return abs(a.first - a.second) > abs(b.first-b.second) ; } );
        
        vector<int> diff(1000001);
        
        for(int i=0;i<n;i++){
            diff[abs(n1[i]-n2[i])]++;
        }
        
        int ub = (int)100001;
        
        for(int i = ub ; i>=1;i-- )
        {
            if(diff[i] >0 ){
                
                if(k >= diff[i]){
                  
                    k -=  diff[i];
                    diff[i-1] += diff[i];
                    diff[i] = 0;
                    
                }
                else{
                    
                    diff[i-1] += k;
                    diff[i] -= k;
                    k = 0;
                    break;
                    
                }
                
            }
        }      
        
        for(long long i = ub ; i>=0;i-- ){

             if(diff[i] ==0)continue;

             ans += (i * i)* diff[i];

         }
        
        
        return ans;
    }
};