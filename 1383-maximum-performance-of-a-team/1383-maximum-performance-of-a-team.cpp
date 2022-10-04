#define pii pair<int,int>
class Solution {
public:
    int maxPerformance(int n, vector<int>& sp, vector<int>& eff, int k) {
     
      //  priority_queue<int, vector<int> , greater<int>> pq;
        
        vector<pii> v;
        
        for(int i=0;i<n;i++){
            v.push_back({eff[i],sp[i]});
        }
        sort(v.begin(),v.end());
        reverse(v.begin(), v.end());
        int j= 0;
        
        priority_queue<pii, vector<pii> , greater<pii>> pq ;
        
        long sum =0 ; long mineff = 1e8 ; long ans = 0;
        for(int i=0;i<n;i++){
            sum += v[i].second;
            mineff = v[i].first;
            pq.push({v[i].second,mineff});
            
           
            if(i>=k){
                sum -= pq.top().first; 
                pq.pop();
            }
             ans = max(ans , 1L*sum * mineff);
            
            
            
        }
        int mod = 1e9+7;
        return ans%mod;
        
    }
};