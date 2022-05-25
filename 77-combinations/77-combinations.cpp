class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ret;
        vector<int> t;
        bt(ret,t,k,n,1);
        
        return ret;
    }
    
    void bt( vector<vector<int>>& ret , vector<int> t , int k,int n, int l){
        
        if(t.size()==k){
    
            ret.emplace_back(t);
            return;
        }
        
        for(int i= l; i<=n; i++){
            
            t.emplace_back(i);
            //cout<<l<< " " << i << " " << endl;
            bt(ret,t,k,n,i+1);
            // cout<<l<< " " << i << " " << endl;
            t.pop_back();
            
        }
        return;
    }
};