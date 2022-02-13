class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        vector<int> ans(t.size() ,0); 
        stack<int> st;
        
        for(int i=0;i <t.size();i++ ){
            
            while(!st.empty() and t[st.top()] < t[i] ){
                
                ans[st.top()] = i-st.top();
                st.pop();
                
            }
            st.push(i); 
        }
            //No need to clear remaining stack elements as they are default 0 in ans.
         
        return ans;
        }

};