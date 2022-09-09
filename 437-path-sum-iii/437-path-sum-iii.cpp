
class Solution {
public:
    long long ans = 0;
    int pathSum(TreeNode* root, int t) {
        dp(root,t);
        return ans;
    }
    
    vector<long long> dp(TreeNode* r, int t)
    {
        
        if(!r)return {};
        
        vector<long long> l = dp(r->left,t);
        vector<long long> ri = dp(r->right,t);
        vector<long long> ret;
        
        for(auto& x:l){
            ret.push_back(x + r->val);
            if(x + r->val==t){
                ans++;
                
                //cout<< x<< " " << r->val << endl;
            }
        }
       
        for(auto &x:ri){
            ret.push_back(x + r->val);
            
            if(x + r->val==t){
                ans++;
                //cout<< x<< " " << r->val << endl;
            }
        }

        if(r->val == t)ans++;
        ret.push_back(r->val);
        
        
        return ret;
        
        
        
    }
    
    
};