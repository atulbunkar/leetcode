class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> mp;
        priority_queue<pair<int,char>> pq;
        
        for(auto x :s)
            mp[x]++;
        
        for(auto x:mp)
            pq.push({x.second,x.first});
        
        int n = s.size();
        
        if(pq.top().first > ceil(n*1.0/2))return "";
        
        string a ="";
        
        while(!pq.empty()){
            auto x = pq.top();
            pq.pop();
            if(a.empty()){
                a += x.second;
                if(x.first>1)
                        pq.push({x.first-1,x.second});
            }
            else{
                if(a.back() == x.second)
                {
                    auto y = pq.top(); pq.pop(); pq.push(x);
                    a += y.second;
                    if(y.first>1)
                        pq.push({y.first-1,y.second});
                            
                }
                else{
                     a += x.second;
                     if(x.first>1)
                        pq.push({x.first-1,x.second});
                    
                }
                
            }
             
        }
        
        return a;
        
    }
};