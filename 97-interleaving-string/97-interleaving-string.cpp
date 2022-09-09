class Solution {
public:
    map<long,bool> mp;
    bool isInterleave(string s1, string s2, string s3) {
        return dp(0,0,0,s1,s2,s3);   
    }
    
    bool dp(int i,int j, int k,string& s1, string &s2, string& s3){
        
        long ki = i*7+ j*13 + k*17;
        
        if(mp.count(ki))return mp[ki] ;
        
        if(k==s3.size()){
            if(i==s1.size() and j==s2.size())return 1;
            return 0;
        }
        
        if(i==s1.size() and j==s2.size()) return 0;
        
        if(i==s1.size()){
            if(s2[j] != s3[k])return mp[ki] = 0;
            return mp[ki] =dp(i,j+1,k+1,s1,s2,s3);
        }
        
        if(j==s2.size()){
            //cout<< 4 ;
            if(s1[i] != s3[k])return 0;
            
            return mp[ki] = dp(i+1,j,k+1,s1,s2,s3);
        }
        
        if(s1[i] == s3[k] and s2[j] == s3[k]){
            //cout << 1 ;
            return mp[ki] = dp(i+1,j,k+1,s1,s2,s3) ||  dp(i,j+1,k+1,s1,s2,s3);
        }
        
        if(s1[i] == s3[k]){
            return mp[ki] =  dp(i+1,j,k+1,s1,s2,s3);
        }
        if(s2[j] == s3[k]){
            //cout<< 3;
            return mp[ki] =  dp(i,j+1,k+1,s1,s2,s3);
        }
        //cout<<2;
        return 0;
        
    }
};