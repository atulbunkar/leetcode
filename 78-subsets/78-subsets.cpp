class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        bitset<1024> b("1") ; 
        int n = nums.size(), p = 1 << n; //get 1 in nth pos in bit, else all 0, i.e 2^n
     
        
        vector<vector<int>> ret(p) ;   //p is size of subset set , i.e 2^n

       for (int i = 0; i < p; i++) {
            for (int j = 0; j < n; j++) {
                cout<<( (i >> j)&1) <<  "  ";
                if ((i >> j) & 1) {    //i>>j & 1 will give number one by one all combinatin of 0,0,0 -> 1,1,1 
                    ret[i].push_back(nums[j]);
                }
            }
           cout<< endl;
       }
        
        return ret ;
    }
 
};