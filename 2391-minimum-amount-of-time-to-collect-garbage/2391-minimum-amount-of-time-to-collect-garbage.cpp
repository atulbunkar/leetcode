class Solution {
public:
    int garbageCollection(vector<string>& ga, vector<int>& t) {
        int ans = 0;
        
        vector<char> kk = {'P', 'G', 'M'};  
        
        int n = ga.size();
        vector<unordered_map<char,int>> v;
        
        for(auto& x:ga){
            unordered_map<char,int> mp;
            for(auto c:x){
                mp[c]++;
            }
            v.push_back(mp);
        }
        
        for(auto& x:kk){
            int tmp =0; 
            
            for(int i=0;i<n;i++){
                
                if(v[i].count(x)){
                   // cout<< i << " ";
                    ans += tmp;
                    ans += v[i][x];
                    tmp =0;
                }
                if(i<n-1)tmp += t[i];
            }
           // cout<< ans << " ";
        }
        
        return ans;
    }
};