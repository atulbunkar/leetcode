class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> cc;
        
        int idx=0;
        
        for(auto x:s){
            if(x==c)cc.push_back(idx);
            idx++;
        }
        
        vector<int> ans;
        
        for(int i=0;i<s.size() ;i++){
            
            if(s[i]==c){ans.push_back(0); continue;}
            
            auto x = lower_bound(cc.begin(),cc.end(), i);
            
            if(x == cc.begin()  ){
                ans.push_back(abs(*x - i) );
                continue;
            }
            if(x== cc.end()){
                ans.push_back(abs(cc[cc.size()-1] - i) );
                continue;
            }
          
            auto y = x-1;
            int pus = min(abs(*x - i) , abs(*y - i));
            ans.push_back(pus );
            
        }
        return ans;
    }
};