class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& po) {
        
        stack<int> s;
        int j = 0; int n = pu.size();
        
        for(int i=0;i<n;i++){
            
            while(!s.empty() and s.top() == po[j]){
                s.pop(); j++;
                //if(!s.empty() and j==po.size())return 0;
            }

           s.push(pu[i]);
             
        }
        
        while(!s.empty() and j<n and s.top() == po[j]){
                s.pop(); j++;
        }
        
        return s.empty();
    }
};