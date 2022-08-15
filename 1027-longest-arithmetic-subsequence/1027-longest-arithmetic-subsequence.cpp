class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
       // unordered_map<string,int> mp; //(st+diff),len
        int n =nums.size(); int ans=1;
        //string k, kk;
        int mp[1001][2002] ;
        memset(mp,-1,sizeof(mp));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                
//                 k = to_string(j) + "," + to_string(nums[i]-nums[j]);
//                 kk = to_string(i) + "," + to_string(nums[i]-nums[j]);
                int d = nums[i]-nums[j];
                d += 1000;
                
                if(mp[j][d] >-1)mp[i][d] = mp[j][d]+1;
                else mp[i][d] = 2;
                
                ans = max(ans, mp[i][d]);
               
            }
        }
        
      
        return ans;
        
    }
};