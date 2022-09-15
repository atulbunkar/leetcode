class Solution {
public:
    int minimumEffort(vector<vector<int>>& t) {
        sort(t.begin(),t.end() , [](vector<int>&a , vector<int>&b){
            if (a[1]-a[0] == b[1]-b[0])return a[1] > b[1];
            return a[1]-a[0]>b[1]-b[0];
            
        }  );
        
        int mn = 0, mx = 1e9,ans = 0;
        
        while(mn<=mx){
            int mid = (mn+mx)/2;
            bool done = 1;
            
            int work = mid;
          
            for(auto &x:t){
                if(x[1] > work ){
                    done = 0;break;
                }
                else
                    work = work - x[0];
            }
            
            if(done){
                ans = mid;
                mx = mid-1;
            }
            else
                mn = mid+1;
           
            //cout<< ans << " ";
        }
        
        return ans;
    }
};