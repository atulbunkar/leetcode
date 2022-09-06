class Solution {
public:
    
    static bool cmp(vector<int>& a, vector<int>& b){
        
        if(a[0]==b[0]){
            return a[1] < b[1];
        }
        return a[0] > b[0];
    }
    
    int numberOfWeakCharacters(vector<vector<int>>& p) {
        sort(p.begin(), p.end(), cmp);
        
        int end = -1; int ans=0;  
        
        stack<int> s; s.push(0);
        
        
        for(int i=0;i< p.size();i++){
             
            if(p[i][1] <  end)ans++;
            
            else
            end =p[i][1] ;
            
        }
        
        return ans;
    }
};