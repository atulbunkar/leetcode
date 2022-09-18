class Solution {
public:
    int validSubarraySize(vector<int>& nums, int t) {
       int n = nums.size();
        
        int left[n],right[n]; //range till which i is minimun
        
        stack<pair<int,int>> st,stt ;
        
        for(int i=0; i<n; i++){
            int cnt = 1;
            while(!st.empty() and st.top().first >= nums[i] ){
                cnt += st.top().second;
                st.pop();
            }
            st.push(make_pair(nums[i],cnt));
            left[i] = cnt;
        }
        
        for(int i=n-1; i>=0; i--){
            int cnt = 1;
            while(!stt.empty() and stt.top().first >= nums[i] ){
                 cnt += stt.top().second;
                 stt.pop();
            }
            stt.push(make_pair(nums[i],cnt));
            right[i] = cnt;
        }
        
        for(int i=0;i<n;i++){
             int a = i - left[i] +1 ; 
             int b = i + right[i] -1 ;
            
           // cout<< a << " " << i << " " << b<<endl;
            
            if( t/(b-a+1) < nums[i] )return b-a+1;
            
        }
        
       return -1;
        
    }
};