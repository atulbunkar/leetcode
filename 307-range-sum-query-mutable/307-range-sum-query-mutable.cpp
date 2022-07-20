class NumArray {
public:
    vector<int> bit; int n; 
    NumArray(vector<int>& nums) {
        n = nums.size();
        bit.resize(n+1,0);
        
        for(int i=0;i<n;i++){
            create(i+1,nums[i]);
        }
        
    }
    
    void create(int index, int val) {
        for(int i=index;i<bit.size();){
            bit[i] += val;
            i += (i&-i);
        } 
    }
    
    void update(int index, int val){
         int diff = val - ( sum(index+1) - sum(index));
      
         for(int i=index+1;i<bit.size();){
            bit[i] += diff;
            i += (i&-i);
        } 
    }
    
    
    int sumRange(int left, int right) {
        return sum(right+1) - sum(left);
    }
    
    int sum(int idx){       //returns sum 1->idx
        if(idx<=0)return 0;
        int ans =0; 
        for(int i=idx;i>0;){ //BIT size is n+1
            ans += bit[i];
            i -= (i&-i);
        }
        return ans;
    }
};

