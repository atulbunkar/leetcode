class Solution {
public:
    vector<vector<int>> mem;
    
    string longestPalindrome(string& s) {
        string ans = s.substr(0,1); 
        
        int n= s.size();
        //memset(mem,-1,sizeof(mem));
        mem.resize(n+1,vector<int>(n+1,-1));
        
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
    
    int ispal(string& s,int i,int j){
        if(i>=j)return 1;
        
        if(mem[i][j] >-1)return mem[i][j] ;
        
        if(s[i]!=s[j])return mem[i][j] = 0;
        return mem[i][j] = ispal(s,i+1,j-1);
    }
    
    
    
    
};