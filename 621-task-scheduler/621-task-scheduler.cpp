class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
     
        unordered_map<char,int> v; 
        int k = 0 , unique= 0;
        
        for(auto c:tasks){
            v[c]++;
            k++;
        }
        priority_queue<int> pq;
        
        for(pair<char, int> count : v) {
            pq.push(count.second); //int,char
        }

        int time = 0 , ans=0;
        
        while(!pq.empty()){
            
            vector<int> t; time = 0;
            for(int i=0;i<n+1;i++){ 
                if(!pq.empty()){
                    t.push_back(pq.top()-1);
                    pq.pop(); 
                    time++;
                }
               
            }
            for(auto x:t){
                if(x>0)pq.push(x);
            }
            ans += !pq.empty() ? n+1 : time;
           
        }
        return ans;
    }
};