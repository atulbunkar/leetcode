class Solution {
public:
    unordered_map<string,int> mp;
    int maxHeight(vector<vector<int>>& cu) {
        
        for(auto& x:cu){
            sort(x.begin(),x.end());
        }
        
        sort(cu.begin(),cu.end());
        
        vector<int> v = {-1,-1};
        
        return dp(0,v,cu);
        
    }
    
    int dp(int i,vector<int>& prev,  vector<vector<int>>& cu  ){
    
         string k = to_string(i) ;
        for(auto& x:prev){
            k +=  "," + to_string(x);
        }
        //cout << k <<endl;
        
        if(mp.count(k))return mp[k];
        
        if(i==cu.size())return 0;
        
        
        if(prev[0] != -1){
            
            if(cu[i][0] <prev[0] || cu[i][1] < prev[1] || cu[i][2] < prev[2])
                return mp[k] = dp(i+1,prev,cu) ;
            
            
        }
        
        return mp[k] = max( dp(i+1, cu[i] ,cu) + cu[i][2] , dp(i+1,prev,cu) );
    }
};