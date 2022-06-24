class Solution {
public:
    long long sumScores(string s) { //z function
        long long n= s.size();
        vector<long long> z(n); 
        
        long long l=0, r=0; z[0] = n;
        
        for(long long i=1; i<n;i++){
           
            if(i>r){
                l= r = i; 
                while(r<n and s[r]==s[r-l])r++; //win size = l (small L, not 1)
                z[i] = r-l;
                r--;        //window of matching string is now from l to r. --r bcoz it went one ahead.
            }
            else{
                if(i+z[i-l] < r+1)  // if it does not touch right bound
                    z[i] = z[i-l];
                
                else{
                    l = i;
                    while(r<n and s[r]==s[r-l])r++;    //start checking from s[0] 
                    z[i] = r-l;
                    r--; 
                }               
            }  
        }
        //for(auto x:z)cout<<x<< " ";
        
        return accumulate(z.begin(),z.end(),0LL);
    }
};