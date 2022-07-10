class Solution {
public:
    int fillCups(vector<int>& a) {
        priority_queue<int> pq;
        for(auto x:a)if(x>0)pq.push(x);
        
        int ans=0;
        while(!pq.empty()){
            int i = pq.top() ,j =0; pq.pop();
            if(!pq.empty()){
                j = pq.top(); pq.pop();
            }
            i--; j--; ans++;
            if(i>0)pq.push(i);
            if(j>0)pq.push(j);
            
        }
       
        return ans;
    }
};