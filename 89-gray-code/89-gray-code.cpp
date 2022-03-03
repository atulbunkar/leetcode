class Solution {
public:
    vector<int> grayCode(int n) {
        int p = 1<<n;
        vector<string> ans;
        ans.push_back("0");
        ans.push_back("1");
        n--;
        
        vector<string> temp;
        while(n--){
            int s = ans.size();
            for(int i= s-1 ; i >= 0 ; i--){ //creating mirror for one's place
                ans.push_back(ans[i]);
            }
            
            for(int i=0; i< s; i++){
                ans[i].insert(0,"0");
            }
            for(int i=0; i< s; i++){
                ans[i+s].insert(0,"1");
            }
      
        }
        //now convert bin to digit
        vector<int> ret;
        
        for(auto x:ans){
            int val=0; int mult = 1;
            
            for(int c = x.size()-1; c >=0 ; c--){
                if(x[c]=='1')
                    val += mult;
                mult *=2;
            }
            
            ret.push_back(val);
        }
        return ret;
    }
};