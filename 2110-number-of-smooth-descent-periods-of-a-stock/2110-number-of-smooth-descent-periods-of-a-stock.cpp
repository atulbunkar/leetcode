class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        int n = p.size();
        long long ans = 1; int j =0;
        
        for(int i=1;i<n;i++){
            
            if(p[i] != p[i-1]-1)j = i;
            
            ans += i-j+1;
            
        }
        
        return ans;
    }
};