class Solution {
public:
    void getleftshort(vector<int>& lft, vector<int>& h){
        
        stack<int> st; int n = h.size();
        
        for(int i= n-1; i >= 0 ; i--){
            
            while(!st.empty() and h[i] < h[st.top()]  ){
                
                lft[st.top()] = i+1;
                st.pop();
            }
            st.push(i);
        }
        
        while(!st.empty()){
            lft[st.top()] = 0;
            st.pop();
        }
        return;
        
    }
    
    void getrightshort(vector<int>& rht, vector<int>& h){
        stack<int> st;  int n = h.size();
        
        for(int i= 0; i < h.size(); i++){
            
            while(!st.empty() and h[i] < h[st.top()]  ){
                
                rht[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()){
            rht[st.top()] = n;
            st.pop();
        }
        return;
    }
    
    int largestRectangleArea(vector<int>& h) {
        int n = h.size();
        vector<int> lft(n); //left range till h[i] is min
        vector<int> rht(n); //right range till h[i] is min
        
        getleftshort(lft,h);   getrightshort(rht,h);
        
        
        int ans = 0;
        
        for(int i=0; i< n;i++){
           // cout<< lft[i] << " " << rht[i]<< endl;
            int area = rht[i]-lft[i];
            area = area*h[i];
            
            ans = max(ans,area); 
            
        }
  
        return ans;
        
    }
};