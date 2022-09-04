class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
       
        int n = s.size();
        
        vector<int> ans(n,INT_MAX);
        int cnt = 0;
        int  i=0;
        
        while(i<n)if(s[i++]==c)break; i--;
        
        for(;i<n;i++){
            if(s[i]==c)cnt = 0;
            ans[i] = cnt++;
        }
        
        cnt = 0; int j=n-1;
        while(j>=0)if(s[j--]==c)break; j++;
        
        for(;j>=0;j--){
            if(s[j]==c)cnt = 0;
            ans[j] = min(ans[j], cnt++);
        }
        
        return ans;
    }
};