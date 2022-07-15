class Solution {
public:
    string minWindow(string s, string t) {
         string ans = ""; int len = INT_MAX-1;
        int n = s.size(); int m = t.size();
       
        vector<int> mp(128); int cnt = m;
 
        for(auto x:t)mp[x-'A']++;
        int j=0,i=0;
        
        while(i<n){ 
            if( mp[s[i] -'A'] >0 ){ 
                cnt--;
            }  
             mp[s[i] -'A']--; //this will red for all chars anyway
            
            while(cnt==0){
                if(i-j < len){
                    len = i-j;
                    ans = s.substr(j,i-j+1);
                }
                
                if(mp[s[j]-'A'] ==0){ 
                    cnt++;
                }
                mp[s[j]-'A']++ ; //this will add for all char anyway
                j++;
            }
            i++;
        }
  
        return len==INT_MAX-1 ? "":ans ;
    }
};