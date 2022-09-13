class Solution {
public:
    int minOperations(vector<int>& t, vector<int>& a) {
        
        map<int , int> mp; //num , idx
        
        int n = a.size();  int m = t.size();
        
        for(int i=0;i<m;i++){
            mp[t[i]] = i;
        }
        
        vector<int> tmp;
        int idx = -1; int ans = 0;
        
        for(int i=0;i<a.size();i++){
            if(!mp.count(a[i]))continue;
            else
                tmp.push_back(mp[a[i]]);
            
        }
        
        vector<int> lis;
        
        for(auto x:tmp){
            
            auto it = lower_bound(lis.begin(),lis.end(),x);
            
            if(it==lis.end())lis.push_back(x);
            else
                *it = x;
            
        }
        
        
        return m - lis.size();
        
    }
};