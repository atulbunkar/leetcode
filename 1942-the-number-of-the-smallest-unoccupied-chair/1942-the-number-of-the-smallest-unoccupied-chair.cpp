class Solution {
public:
    static bool cmp(vector<int>&i, vector<int>&j){
        if(i[0]==j[0])return i[1]>j[1];
        return i[0]<j[0];
    }

    int smallestChair(vector<vector<int>>& t, int idx) {
        vector<vector<int>> v;
        unordered_map<int,int>  sc; //st , chair
        unordered_map<int,vector<int>> es; //end ,st
        
        int tar = t[idx][0];
        
        for(auto&x:t){
            v.push_back({x[0],0});
            v.push_back({x[1],1});
            es[x[1]].push_back(x[0]);
           
        }
        sort(v.begin(),v.end(),cmp);
        
        priority_queue<int, vector<int> , greater<int>> pq;
        for(int i=0;i<t.size();i++)pq.push(i);
        
        int i=0;
        for(auto&x :v){
            
            if(x[1]==1){
               auto& st = es[x[0]];
                pq.push(sc[st[0]]);
                es[x[0]].erase(es[x[0]].begin());
                
            }
            else{
                sc[x[0]] = pq.top(); pq.pop();
                if(x[0]==tar)return sc[x[0]];
            }
            
    
        }
        
        
        return -1;
        
    }
};