class Solution {
public:
    
     int mem[2001][2001]; int mem2[2001]; bool flag = false;
    
    bool checkPartitioning(string s) {
         int n=s.size();   memset(mem,-1,sizeof(mem)); 
        if(n==3)return 1; 
         
        return part(0,3,s);
    }
    
    bool part(int i,int k,string& s){
        int n = s.size();
        
        
         if(i>=n)return 0;
        if(k==1)return ispal(s,i,n-1);
       
        bool ans =0;
        
        for(int j=i; j<n;j++){
            
            if(ispal(s,i,j))ans |= part(j+1,k-1,s);
            
        }
        
        return ans;
        
    }
    
     
     
    bool ispal(string& s, int i,int j){ //after a few calls , our mem table is full to use
        if(j<=i)return 1;
        
        if(mem[i][j] != -1)return mem[i][j] ;
        
        if(s[i]==s[j])return mem[i][j] = ispal(s,i+1,j-1);
        return  mem[i][j] = 0;
    }
};