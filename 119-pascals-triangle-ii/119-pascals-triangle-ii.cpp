class Solution {
public:
    vector<int> getRow(int r) {
        vector<int> v; 
        v.push_back(1);
        
        int sz = 2;
        
        while(r--){
            vector<int> t(sz);
            t[0] = 1; t[t.size()-1] =1;
            
            for(int i=1; i < sz-1; i++){
                t[i] = (v[i-1]+v[i]);
            }
            
            v = t;
            sz++;
        }
        
        return v;
        
    }
};