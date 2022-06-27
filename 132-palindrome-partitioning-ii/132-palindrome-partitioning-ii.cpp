class Solution {
public:
    int ans,ret;  int mem[2001][2001]; int mem2[2001];
    
    int minCut(string s) {
        int n=s.size();   memset(mem,-1,sizeof(mem)); memset(mem2,-1,sizeof(mem2));
        if(n==1)return 0; 
        ret = INT_MAX; ans = 0;  
        
        return all(s,0);      
        
    }
    
     int all(string& s ,int x){ //this code basically tells how many partitions can be done
        if(x>=s.size()){
            return -1; //-1 bcoz no of partitions -1 to return
        } 
         
        if(mem2[x]!=-1)return mem2[x];
         
         int tmp = INT_MAX;
 
        for(int i=x; i<s.size() ; i++){
            if(ispal(s, x, i)){    
                tmp = min(all(s,i+1) +1,tmp ) ; //partition it and call for i+1 ,backtrack and check for longer strings
            }
        } 
        return mem2[x] = tmp;   
    }
    
    bool ispal(string& s, int i,int j){ //after a few calls , our mem table is full to use
        if(j<=i)return 1;
        
        if(mem[i][j] != -1)return mem[i][j] ;
        
        if(s[i]==s[j])return mem[i][j] = ispal(s,i+1,j-1);
        return  mem[i][j] = 0;
    }
};