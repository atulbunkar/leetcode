class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        
        int left[n],right[n]; //range till which i is minimun
        
        stack<pair<int,int>> st,stt ;
        
        for(int i=0; i<n; i++){
            int cnt = 1;
            while(!st.empty() and st.top().first > nums[i] ){
                
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
        
        long long ans = 0 ,temp; 
        long long sum[n]; 
        sum[0] = nums[0];
        
        for(int i = 1 ; i < n ; i++ ){
            sum[i] = sum[i-1] + nums[i]; 
        }
        
        for(int i=0;i <n ;i++){
            int a = i - left[i] +1 ; 
            int b = i + right[i] -1 ;
            
            if(a>0)
                temp = sum[b] - sum[a-1] ;
            else
                temp = sum[b];
            
            ans = max(temp*nums[i],ans);
        }

        return ans%1000000007;
            
    }
};