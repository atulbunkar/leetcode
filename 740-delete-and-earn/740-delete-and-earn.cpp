class Solution {
public:
    int mem[100001];
    int deleteAndEarn(vector<int>& nums) {
        map<int,int> mp;
        for(auto x:nums)mp[x]++; // num,count
        vector<pair<int,int>> v;  
       memset(mem,-1,sizeof(mem));
        
        for(auto x:mp)v.push_back(make_pair(x.first,x.second));
            
        return dp(0,v);
    }
    
    int dp(int i , vector<pair<int,int>>& v){
        
        if (i>=v.size())return 0;
        if(i== v.size()-1)return v[i].first * v[i].second;
        
        if(mem[i] != -1)return mem[i];
        
        if(v[i+1].first == v[i].first+1){
            return  mem[i] = max(dp(i+2,v)+v[i].first * v[i].second, dp(i+1,v));
        }
        else{
            return  mem[i] = dp(i+1,v) +v[i].first * v[i].second;
        }

    }
};