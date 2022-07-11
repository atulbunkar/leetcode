class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()== 0)return 0;
        if(haystack.size()== 0 and needle.size()== 0){return 0;}
        int n = needle.size();
        int m = haystack.size();        
         vector<int> lps(n,0);
         z(lps, needle); 
        
        
         int j=0;
        
        for(int i=0; i<m ; ){
            
            if(haystack[i]==needle[j]){
                ++j;
                i++;
            }
            
            
            else{
                if(j==0)i++;
                else
                    j = lps[j-1];  
            }    
            cout<< haystack[i] << " " << j<<endl;
            if(j==n)return i-j ;
            
           
        }        
                 
        return -1;
    }
    
    
    void z(vector<int>& lps , string& t){
        int n = t.size();
        int idx=0;
        for(int i=1;i<n; ){
            if(t[i]==t[idx]){
                lps[i] = ++idx;
                i++;
            }
            else{
                if(idx==0)i++;
                else
                    idx = lps[idx-1];  
            }  
            
        }   
    }
};