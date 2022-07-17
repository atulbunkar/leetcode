class Solution {
public:
    bool checkPalindromeFormation(string a, string b) {
        int n= a.size();
        if(ispal(a,0,n-1) || ispal(b,0,n-1))return true;
        
        
        int i=0, j=n-1;
        int ans=0;
        
        while(i<n){
            if(a[i] != b[j])break;
             if(ispal(a,i+1,j-1) || ispal(b,i+1,j-1))return true;
             if(i==j-2 || i==j-1 || i==j)return true;
            i++;j--;
        }
        
    
        
        i=0; j=n-1;
        while(i<n){
            if(a[j] != b[i]) break;
            if(ispal(a,i+1,j-1) || ispal(b,i+1,j-1))return true;
           if(i==j-2 || i==j-1 || i==j)return true;
            i++;j--;
        }
      
      
        
        return false;
        
    }
    
    bool ispal(string&s , int i,int j){
        if(i<0 ||j>s.size()-1)return false;
        
        while(i<j){
            if(s[i++]!=s[j--])return false;
        }
        
        return true;
    }
    
    
};