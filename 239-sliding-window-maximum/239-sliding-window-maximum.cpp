class Solution {
public:
    // MONOTONIC QUEUE IMPLEMENTATION
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans; 
        
        priority_queue<pair<int,int>> pq;
        
        int maxx = INT_MIN, j=0; 
        
        for(int i=0;i<n;i++){
            
            if(i<k-1)pq.push({nums[i],i});
            
            else{
                pq.push({nums[i],i});
                while(!pq.empty() and pq.top().second < i-k+1)pq.pop();
                ans.push_back(pq.top().first);
                
               
            }
            
        }
        
        
       
        return ans;
        
    }
};