class Solution {
public:
    int lastStoneWeightII(vector<int>& st) {
        int n = st.size();
        vector<int> dp(n);
       
        int ans = INT_MAX;
        
        unordered_set<int> s = {0}; //set to ignore duplicates
        
        for(auto n : st){
            
            unordered_set<int> t = s;   //filling t with prev elements of s
            
            s= {};       //clear prev data. after loop, will use only elements filled in last iteration.
            
            for(auto x: t){
                s.insert(n-x);
                s.insert(n+x);
            }
        }
        
         for(auto n : s){
            ans = min(ans, abs(n));
        }
        
        return ans;
        
    }
};