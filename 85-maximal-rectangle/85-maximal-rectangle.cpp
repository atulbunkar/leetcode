class Solution {
public:
    int maximalRectangle(vector<vector<char>>& mt) {
        int n= mt.size(), m = mt[0].size();
        
        vector<vector<int>> t(n, vector<int>(m,0));
        
        for(int j=0;j<m;j++)t[0][j] = mt[0][j]=='1';
        
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                if(mt[i][j] == '1')t[i][j] = t[i-1][j]+1;
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++)
              ans = max(ans, largestRectangleArea(t[i]) );
       
       
        return ans;         
    }
    
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