class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        unordered_map<string,int> mp;
        mp["+"] = 1; 
        mp["-"] = 2;  
        mp["*"] = 3; 
        mp["/"] = 4;
        
        stack<int> st;
        
        for(auto x:tokens){
            if(!mp[x])
                st.push(stoi(x));
            else{
                int sec = st.top(); st.pop();
                int fir = st.top(); st.pop();
                
                if(mp[x] ==1)st.push(fir+sec);
                else if(mp[x] ==2)st.push(fir-sec);
                else if(mp[x] ==3)st.push(fir*sec);
                else st.push(fir/sec);
                
            }
        }
        
        return st.top();
        
        
    }
};