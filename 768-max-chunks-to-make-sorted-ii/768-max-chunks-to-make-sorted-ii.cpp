class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int ans = arr.size();
        int n = arr.size();     stack<int> st;
        
        for(int i = 0 ; i < n ; i++){
            int curmax = st.empty()?arr[i]: max(st.top(),arr[i]);
            
            while(!st.empty() and arr[i] < st.top()){
                st.pop();
            }
            st.push(curmax);
        }
        
        return st.size();
    }
};