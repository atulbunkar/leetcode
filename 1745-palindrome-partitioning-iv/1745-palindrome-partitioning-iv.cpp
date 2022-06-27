class Solution {
public:
    
       int mem[2001][2001]; int mem2[2001]; bool flag = false;
    
    bool checkPartitioning(string s) {
         int n=s.size();   memset(mem,-1,sizeof(mem)); 
        if(n==1)return 0; 
        bool ans;
        
        for(int i=0;i<n;i++){
            
            for(int j=i+1; j<n-1;j++){
                
                if(ispal(s,0,i) and ispal(s,i+1,j) and ispal(s,j+1,n-1) )return true;
                
            }
            
        }
        
        
        return false;    
    }
    
     
     
    bool ispal(string& s, int i,int j){ //after a few calls , our mem table is full to use
        if(j<=i)return 1;
        
        if(mem[i][j] != -1)return mem[i][j] ;
        
        if(s[i]==s[j])return mem[i][j] = ispal(s,i+1,j-1);
        return  mem[i][j] = 0;
    }
};