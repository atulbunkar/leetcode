class NumArray {
public:
    vector<int> st ; int n;
    
    void build(int lr,int rr, int idx , vector<int>& nums ){
        
        if(lr>rr)return;
        
        if(lr==rr){st[idx] = nums[lr]; return;}
        
        int mid  = (lr+rr)/2;
        
        build(lr,mid,2*idx+1,nums);
        build(mid+1, rr, 2*idx+2,nums);
        
        st[idx] = st[2*idx+1] + st[2*idx+2];
        
    }
    
    NumArray(vector<int>& nums) {
        n = nums.size();
        st.resize(4*n+4);
         build(0,n-1,0,nums);
    }
    
    void update(int index, int val) { 
     
        updt(0,0,n-1 ,  index,val);
    }
    
    void updt(int idx, int lr,int rr,  int i,int val){
        if(lr==rr){st[idx] = val; return;}
        if(i < lr || i > rr)return;
        
        int mid = (lr+rr)/2;
        
        if(i <= mid){
            updt(2*idx+1, lr , mid , i,val);
        }
        else{
            updt(2*idx+2,mid+1,rr,i,val);
        }
        
        st[idx] = st[2*idx+1] + st[2*idx+2];
        
    }
    
    int sumRange(int left, int right) {
     
        return sum(0, 0, n-1, left, right);
    }
    
    int sum(int idx , int lr, int rr, int l, int r){
        
        if(rr < l)return 0;
        
        if(lr > r)return 0;
        
        if(l>r)return 0;
        int mid= (lr+rr)/2;
        
        if(lr==l and rr==r){
            return st[idx];
        }
        
        return sum(2*idx+1, lr , mid , l, min(r,mid) )  + sum(2*idx+2 , mid+1,rr, max(l,mid+1) , r  );
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */