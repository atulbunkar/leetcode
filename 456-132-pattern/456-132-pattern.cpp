class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        bool gotup = false ,gotdown = false;
        int max_k = INT_MIN;
        stack<int> s;
        
        for(int i=nums.size()-1; i>=0;i--){
            
            while(!s.empty() and nums[i]>s.top()){
                max_k = max(max_k,s.top());
                s.pop();
            }
            s.push(nums[i]);
            if(nums[i] < max_k)
                return true;
            
        }
        
    return false;
    }
};