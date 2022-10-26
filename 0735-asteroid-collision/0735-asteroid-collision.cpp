class Solution {
public:
    vector<int> asteroidCollision(vector<int>& a) {
        stack<int> s;
        
        for(int i=0;i<a.size();i++){
            
            if(s.empty())s.push(a[i]);
            
            else{
                int f =1;
                while(!s.empty() and a[i] <0 and s.top() > 0 ){
                    
                    if(abs(s.top()) > abs(a[i])){
                        f = 0;
                        break;
                    }
                    else if(abs(s.top()) < abs(a[i])){
                        s.pop();
                    }
                    else{
                        s.pop();
                        f=0;
                        break;
                    }
                }
                if(f)s.push(a[i]);
            }
            
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};