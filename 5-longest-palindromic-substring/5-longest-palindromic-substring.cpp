class Solution {
public:
    bool mem[1001][1001];
    
    string longestPalindrome(string& s) {
        string ans = s.substr(0,1); 
        
        int n= s.size();
        memset(mem,false,sizeof(mem));
        
        for(int i=0; i<n-1; i++){
            for(int j=n-1; j>i; j--){
                
                if(ispal(s,i,j)){
                    if(j-i+1 > ans.size()){
                        ans = s.substr(i,j-i+1);
                        
                    }
                    break;
                }
            } 
        }
        return ans;
    }
    
    bool ispal(string& s,int i,int j){
        if(i>=j)return 1;
        
        if(mem[i][j] )return mem[i] ;
        
        if(s[i]!=s[j])return mem[i][j] = 0;
        return mem[i][j] = ispal(s,i+1,j-1);
    }
    
    
    
    
};