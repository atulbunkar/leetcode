#define pii pair<long,long>
class Solution {
public:
    int maximumRobots(vector<int>& c, vector<int>& rr, long long b) {
        vector<long> r(rr.size(),0); r[0] = rr[0];
        
        for(int i=1;i<r.size();i++){
            r[i] = rr[i] + r[i-1];
        }
        
        priority_queue<pii> pq;
        
        int i=0,j=0;
        int ans = 0;  long mx = c[0];
        
        for(;i<c.size();i++){
             pq.push({c[i],i});
            
            while(!pq.empty() and (pq.top().first + (long)(i-j+1)*(r[i] - ((j>0)? r[j-1]:0)  )) > b ){
               
                while(!pq.empty() and pq.top().second <= j)pq.pop();
                j++;
               // if(j==i)break;
            }
            
            if(!pq.empty()){
           long bud = (pq.top().first + (long)(i-j+1)*(r[i] - ((j>0)? r[j-1]:0)  ));
            if(bud <= b)ans = max(ans,i-j +1);
            }
           
            
        }
        
        return ans;
        
        
        
    }
};