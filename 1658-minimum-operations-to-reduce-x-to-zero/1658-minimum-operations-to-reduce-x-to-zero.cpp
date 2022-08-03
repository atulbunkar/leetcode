class Solution {
public:

    int minOperations(vector<int>& nums, int x) {
         int ans=INT_MAX;         int n = nums.size();

        long long  s = 0;//accumulate(nums.begin(),nums.end(),0);
        
        for(int i=0;i<n;i++)
            s = (long long)nums[i] + s;
        
        //if(x>s)return -1;
        int want = s -x;
        
        map<long long ,int> mp; // sum,idx

        mp[0] = -1; long long ss = 0; int a = -1;
        int j=0;
        for(int i=0;i<n;i++){
            ss = (long long)nums[i] + ss;
            mp[ss] = i;
            
            if(mp.count(ss-want)){
                a = max(a, i-mp[ss-want]);
            }
            
            
            
        }
        return a == -1? -1: n-a;
           
    }
    
};