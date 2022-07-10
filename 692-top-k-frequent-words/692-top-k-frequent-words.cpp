class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>> pq;
        
        map<string,int> mp;
        map<int , vector<string> , greater<int> > mp2;
        
        for(auto x:words)
            mp[x]++;
        
        for(auto x:mp){
            mp2[x.second].push_back(x.first);
        }
        
        vector<string> ans;
        
        for(auto x:mp2){
            if(k<=0)break;
            vector<string> t = x.second;
            sort(t.begin(),t.end());
            
            if(k<t.size())
                ans.insert(ans.end() , t.begin(), t.begin()+k);
            else
                ans.insert(ans.end() , t.begin(), t.end());
            
            k -= t.size();
        }
        
        
        return ans;
        
    }
};