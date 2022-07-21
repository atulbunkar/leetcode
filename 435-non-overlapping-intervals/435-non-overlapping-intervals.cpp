class Solution {
public:
    static bool cmp(vector<int>&a ,vector<int>&b){
        return a[1]<b[1];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intr) {
        sort(intr.begin(),intr.end(),cmp);
        int ans=0;
        
        int i=0 , n = intr.size();
        
        
        while(i<n){
            
            int s = intr[i][0] , e = intr[i][1];
            
            int j=i+1;
            
            while(j<n and intr[j][0] < e){
                ans++;
                j++;
            }
            i = j;
            
        }
        
      
        
        return ans;
        
    }
};