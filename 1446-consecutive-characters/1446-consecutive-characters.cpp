class Solution {
public:
    int maxPower(string s) {
        int i=0,j=0, n=s.size();
        int ans = 1;
        while(i<n){
            
            if(i==n-1){
                ans = max(ans,i-j+1);
                break;
            }
            
            if(s[i+1]==s[i])i++;
            else{
                ans = max(ans, i-j+1);
                j= i+1;
                i++;
            }
            
        }
        return ans;
    }
};