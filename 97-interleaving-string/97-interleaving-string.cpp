class Solution {
public:
    int mem[102][102][202];
    
    bool isInterleave(string& s1, string& s2, string& s3 ,int i=0, int j=0 ,int k=0) {
        
        if(k==0)
            memset(mem,-1,sizeof(mem));
        
        if(k==s3.size())return i==s1.size() and j==s2.size();
        
        if(mem[i][j][k] != -1)return mem[i][j][k];
        
        bool x=0,y=0,z=0;
        if(s1[i] == s3[k])
            x = isInterleave(s1,s2,s3,i+1,j,k+1);
        
        if(s2[j]==s3[k])
            y = isInterleave(s1,s2,s3,i,j+1,k+1);
        
        return mem[i][j][k] = x||y; 
        
    }
};