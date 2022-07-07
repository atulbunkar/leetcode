class NumArray {
public:
    vector<int> nums;  vector<int> st;
    NumArray(vector<int>& num){
        nums = num;
        int size = nums.size()+1;  
        int ht = ceil(log2(size)); 
        size = ceil(pow(2,ht+1)) ;
         cout<<ht <<  " " << size; 
        st.resize(size,0);
         make(0,0,nums.size()-1);
    }
    
    int make(int idx, int i,int j){
        
        if(i==j){
            return st[idx] = nums[i];
        }
        return st[idx] = make( 2*idx+1 ,i,(i+j)/2 ) + make( 2*idx+2, (i+j)/2+1,j ) ;
        
    }
    
    void update(int index, int val) {
        int diff = val - nums[index];
        nums[index] = val;
        updt(0,0,nums.size()-1, index, diff);
    }
    
    int sumRange(int left, int right) {
        
        int i=0, j= nums.size()-1, idx = 0;
        return sumr(left,right, i,j,idx);
        
    }
    
    int sumr(int l,int r, int i,int j,int idx){
        if(l>j)return 0;
        if(r<i)return 0;
        
        if(l<=i and r>=j){
            return st[idx];
        }
        return sumr(l,r,i,(i+j)/2,2*idx+1) + sumr(l,r,(i+j)/2+1,j,2*idx+2);
        
    }
    
    void updt(int idx,int i,int j, int changeidx, int diff){
        
        if(idx >= st.size() || j< changeidx || i > changeidx)return ;
        
        if(j>=changeidx and i<= changeidx){
            st[idx] = st[idx]+diff;
        }
        if(i==j)return;
        
        updt(2*idx+1,i,(i+j)/2 , changeidx,diff );
        updt(2*idx+2,(i+j)/2+1 ,j, changeidx,diff );
    }
   
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */