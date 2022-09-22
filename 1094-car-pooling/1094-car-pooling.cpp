class Solution {
public:
    bool carPooling(vector<vector<int>>& t, int cap) {
        int road[1005] = {0};
        
        for(auto x:t){
            road[x[1]] += x[0];
            if(x[0]>cap)return 0;
            road[x[2]] -= x[0];
            
        }
        
        for(int i =1;i< 1005;i++){
            
            road[i] += road[i-1];
            if(road[i] > cap)return 0;
            
        }
        return 1;
        
    }
};