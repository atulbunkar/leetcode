class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st; int i=0;
 
        for(auto c:s){
            
            if(c == '(')st.push(c-41);
           // cout<< i <<" ";
            if(c == ')'){
                if(st.top() == -1){
                    st.pop();
                    if(!st.empty() and st.top() != -1){
                        int x = (st.top()); st.pop();
                        st.push((x+1));
                       
                    }
                    else{
                        st.push(1);
                    }
                }
                else{
                    int x = (st.top()); st.pop();
                    while(!st.empty() and st.top() != -1){x = x + (st.top()); st.pop(); }
                    x = 2*x;
                    st.pop();
                    st.push((x));
                    
                }
            }
            //cout<< st.top() << endl;
            i++;
        }
        
        int b = 0; 
        while(!st.empty()){
            //cout<< st.top();
            b += (st.top()); 
            st.pop();
        }
        
        return b;
    }
};