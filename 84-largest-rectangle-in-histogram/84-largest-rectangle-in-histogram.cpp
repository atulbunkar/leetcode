class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        int n= h.size();
        vector<int> left(n),right(n);
        getfromleft(h,left);
         getfromright(h,right);
        
        int ans = 0;
        
        for(int i=0;i<n;i++){
            ans = max(ans , (h[i])*( right[i]-left[i] +1));
        }
        
        
        return ans;
    }
    
    void getfromleft(vector<int>& h , vector<int>& left){
         stack<int> st; int n= h.size();
         st.push(0); left[0] = 0;
        
         for(int i=1;i<n;i++){
             
             while(!st.empty() and h[st.top()] >= h[i]){
                 st.pop();
             }
             if(st.empty())left[i]=0;
             else left[i] = st.top()+1;
             
             st.push(i);
         }
    
    }
    
    void getfromright(vector<int>& h , vector<int>& right){
        stack<int> st; int n= h.size();
         st.push(n-1); right[n-1] = n-1;
        
         for(int i=n-2;i>=0;i--){
             
             while(!st.empty() and h[st.top()] >= h[i]){
                 st.pop();
             }
             if(st.empty())right[i]=n-1;
             else right[i] = st.top()-1;
             
             st.push(i);
         }
    }
};