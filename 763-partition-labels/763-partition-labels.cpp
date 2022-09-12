class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> c(26,0); int n = s.size();
        
        for(int i=0;i<n;i++){
            c[s[i]-'a'] = i;
        }
        
        vector<int> ans; int tmp = 1;
        
        int i=0; int newend,maxend = -1;
        
        while(i<n){
            
            newend = c[s[i]-'a'];
            maxend = max(maxend,newend);
            
            if(maxend == i){
                ans.push_back(tmp);
                tmp = 0;
            }
            tmp++;
            i++;
            
        }
        
        return ans;
        
    }
};