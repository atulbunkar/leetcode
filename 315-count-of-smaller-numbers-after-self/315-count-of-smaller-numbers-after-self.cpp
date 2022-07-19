class Fenwick{
  vector<int> bit; int sz;
public:
    Fenwick(int _sz){
        sz = _sz;
        bit.resize(sz,0);
    }
    void update(int i,int val){
        while(i<sz){
            bit[i] += val;
            i += (i&-i);
        }
        
    }
    int sum(int i){
        int ans=0;
        while(i>0){
            ans += bit[i];
            i -= (i&-i);
        }
        return ans;
    }
};

class Solution {
public:
 
    vector<int> countSmaller(vector<int>& nums) {
        int minn = *min_element(nums.begin(),nums.end()),maxx=*max_element(nums.begin(),nums.end());
          int n = nums.size();
        vector<int>result(n,0);
        int bitsize = maxx-minn+1;
        Fenwick bit(maxx-minn+2);
        
        for(int i=n-1;i>=0;i--){
            
            result[i] = bit.sum(nums[i]-minn);
            bit.update(nums[i]-minn+1,1);
            
        }
        return result;
    }
};


