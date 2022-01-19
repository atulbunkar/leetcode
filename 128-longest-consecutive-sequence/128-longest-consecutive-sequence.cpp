class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        int n= nums.size();
        if(n==0)return 0;
        
         for(int i=0; i<nums.size(); i++)
            s.insert(nums[i]);
        
         int ans = 0, c=1;
        
        while(!s.empty()){
            int t = *s.begin();
            int tt = t-1;
            
            int to = t+1;
            s.erase(t);
            
            c = 1;
            while(s.count(to)){
                c++;
                s.erase(to);
                to = to+1;
            }
             while(s.count(tt)){
                c++;
                s.erase(tt);
                tt = tt-1;
            }
            
            ans = max(ans, c);
          
        }
        
       
        return ans;
    }
};