class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        vector<int> mq;
        
        int n= nums.size();
        for(int i=0;i<n;i++){
            int curr = nums[i];
            
            auto it = lower_bound(mq.begin(),mq.end(),curr);
            
            if(it==mq.end())mq.push_back(curr);
            
            else
                *it = curr;
            
            //cout<< it-mq.begin() << " ";
            
            if(mq.size()==3)return true;
    
        }
        
        return false;
        
    }
};