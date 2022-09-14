class Solution {
public:
    int longestWPI(vector<int>& hrs) {
        for(auto &x:hrs){
            x = x>8?1:-1;
        }
        
        int cnt = 0;
        map<int,int> mp;
        mp[1] = 0;
        int ans = 0,sum =0;
        int i=0;
        for(auto x:hrs){
            sum += x;
            
            if(sum>=1)
                ans = max(ans,i+1);
            else
            {
                if(mp.count(sum-1))ans = max(ans,i-mp[sum-1]);
            }
            
            if(!mp.count(sum)) mp[sum] = i;
            i++;
        }
        
        return ans;
        
    }
};