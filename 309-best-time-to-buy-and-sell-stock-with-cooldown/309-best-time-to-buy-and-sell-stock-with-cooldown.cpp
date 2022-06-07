class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n = p.size();
        vector<int> s1(n+1),s2(n+1) ,s3(n+1) ;
        
        s1[0] = 0; s2[0] = -p[0] ; s3[0] = INT_MIN;
        
        for(int i=1; i<n ;i++){
            
            s1[i] = max(s3[i-1]  , s1[i-1]) ; //rest from s3 or rest in it only
            
            s2[i] = max(s1[i-1] -p[i]  , s2[i-1]) ; // buy from s1 or rest in s2
            
            s3[i] = s2[i-1]  + p[i]; //sell after buy from s2
        }
        
        return max(s1[n-1],s3[n-1]);
        
    }
    
    
       
        
        
        

};