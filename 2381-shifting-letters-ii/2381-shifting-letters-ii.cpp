class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& sh) {
        int n =s.size();
        vector<int> v(n+1);
        
        for(auto x:sh){
            if(x[2]==1){
                v[x[0]]++;
                v[x[1]+1]--;
            } 
            else{
                v[x[0]]--;
                v[x[1]+1]++;
            }
        }
        
        for(int i=1;i<=n;i++){
            v[i] += v[i-1];
            v[i] = v[i]%26;
        }
        v[0] = v[0]%26;
        
        int i=0;
        for(auto& c:s){
           int inc =  (c -'a' + v[i])%26;
            inc = (inc+26)%26;
           c = inc + 'a' ;
               
             i++;
        }
        
        return s;
    }
};