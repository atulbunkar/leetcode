class Solution {
public:
    
    string clear(string s){
        stack<char> st;
        string ret ="";
        
        for(auto c:s){
            if(st.empty())st.push(c);
            else{ 
                if(st.top() == '[' and c== ']')st.pop();
                else st.push(c); 
            } 
        }
        while(!st.empty()) {
            ret.push_back(st.top());
            st.pop();
        }   
        return ret;
         
    }
   
    int minSwaps(string s) {
            int n =s.size();
        
    
        int ans = 0 ; int i=0,j=n-1,bal =0;
        
        while(1){
             
            while(i<n){
                if(s[i]=='[')bal++;
                else bal--;
                
                if(bal < 0)break;
                i++; 
            }
            while(j>i){
                if(s[j]=='[')break;
                j--;
            }
            if(i==n)break;
            swap(s[i],s[j]);
            bal++;
            
            ans++;
            
        //cout << s << " ";
        }
        return ans;
    }
};