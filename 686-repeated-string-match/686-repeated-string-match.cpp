class Solution {
public:
    int repeatedStringMatch(string a, string b) {
        if(b=="")return 0;
        int n=b.size(), m = a.size();
        
        int ans=1; int k = n/m+ 5;  string c =a;
            
        while(ans <=k){
            if(a.find(b) != string::npos){

                return ans;
            }
            ans++;
            a += c;
        }
        
        return -1;
        
    }
};