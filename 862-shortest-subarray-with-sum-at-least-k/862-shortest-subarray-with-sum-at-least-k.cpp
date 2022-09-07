
typedef long long ll;
typedef pair<ll,ll> pll;

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        
        priority_queue<pll , vector<pll> ,greater<pll> >pq; //sum, idx
        
        
        int n = nums.size();
        int ans = 1e7;
        
        long long sum =0;
        
        for(int i=0;i<n;i++){
             sum += nums[i];
            
            if(sum >=k){
                ans = min(ans, i+1);
            }
            
           
            while(!pq.empty() and sum - pq.top().first >= k){
                
                ans = min(ans , i-(int)pq.top().second );
                pq.pop();
            }
            
            pq.push({sum,i});
            
          
            
        }
        
        return ans == 1e7? -1:ans;
    }
};