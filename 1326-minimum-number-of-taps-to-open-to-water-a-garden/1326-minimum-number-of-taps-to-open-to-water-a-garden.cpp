class Solution {
public:
    int minTaps(int n, vector<int>& r) {
        
        vector<vector<int>> v; int m =r.size();
        
        for(int i=0;i<m;i++){
            if(r[i]==0)continue;
            v.push_back({  max(0,i-r[i]), min(n,i+r[i])  });
        }
        
       
        
        sort(v.begin(),v.end(),[](vector<int>& a,vector<int>&b ){
            if(a[0]==b[0])return a[1] > b[1];
            return a[0] < b[0];
        } ) ;
        
      //  for(auto x:v)cout<< x[0] << " " <<x[1]<< endl;
        
         int st = 0; int end =0;  int ans = 0;
        m = v.size();
        for(int i=0;i<m;){
            
            if(v[i][0] > end)return -1;
           
            int j=i+1; int newend = max(end,v[i][1]); 
            
            while(j<m and v[j][0] <= end){
                newend = max(newend, v[j][1]);
                j++;
            }
            end = newend;
            i = j;
            ans++;
            if(end == n)break;
        }
        
        return end<n ?-1:ans;
    }
};