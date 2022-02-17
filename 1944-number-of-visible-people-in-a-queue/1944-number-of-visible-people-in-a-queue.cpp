class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& h) {
        stack<int> st; int n = h.size();
        vector<int> ans(n);
        
        for(int i=n-1;i>=0 ; i--){
            
            while(!st.empty() and h[st.top()] <= h[i]){
                ans[i]++ ;
                st.pop();
                
            }
            
            if(!st.empty())ans[i]++;
            
            st.push(i);
        }
        
  
        
        return ans;
    }
};