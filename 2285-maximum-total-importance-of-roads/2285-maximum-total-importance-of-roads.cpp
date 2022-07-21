#define ll long long
class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<ll,ll> imp;
        multimap<ll,ll> imp2;
        
        for(auto x:roads){
            imp[x[0]]++;
            imp[x[1]]++;
        }
        
        for(auto& x: imp)
            imp2.insert({-1*x.second , x.first});
            
      
        vector<ll> imp3(n);
        
        int val = n; 
        
        for(auto& x:imp2){ //inc order
            imp3[x.second] = val--;
            
        }
        
        ll ans = 0;
        for(auto& x:roads){
            ans = ans + imp3[x[0]] + imp3[x[1]] ;
        }
        
        return ans;
        
    }
};