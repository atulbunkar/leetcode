class Solution {
public:
    int lastStoneWeightII(vector<int>& st) {
  
        int ans = INT_MAX;
        
        set<int> s,t;
        s.insert(0);
        
        for(auto n:st){
            t =s;
            s.clear();
            for(auto x:t){
                s.insert(n-x);
                s.insert(n+x);
            }
        }
        
       // int ans = INT_MAX;
        for(int x:s)
            ans = min(ans,abs(x));
        
        return ans ;
        
        
    }
};