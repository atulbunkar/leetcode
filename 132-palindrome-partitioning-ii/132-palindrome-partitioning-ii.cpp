class Solution {
public:
    int ans,ret;  int mem[2001][2001]; int mem2[2001];
    
    int minCut(string s) {
        int n=s.size();   memset(mem,-1,sizeof(mem)); memset(mem2,-1,sizeof(mem2));
        if(n==1)return 0; 
        ret = INT_MAX; ans = 0;  
        
        return all(s,0);      
        
    }
    
     int all(string& s ,int x){
        if(x>=s.size()){
            return -1;
        } 
         
        if(mem2[x]!=-1)return mem2[x];
         
         int tmp = INT_MAX;
 
        for(int i=x; i< s.size() ; i++){
            if(ispal(s, x, i)){    
                tmp = min(all(s,i+1) +1,tmp ) ; 
            }
        } 
        return mem2[x] = tmp;   
    }
    
    bool ispal(string& s, int i,int j){
        if(j<=i)return 1;
        
        if(mem[i][j] != -1)return mem[i][j] ;
        
        if(s[i]==s[j])return mem[i][j] = ispal(s,i+1,j-1);
        return  mem[i][j] = 0;
    }
};