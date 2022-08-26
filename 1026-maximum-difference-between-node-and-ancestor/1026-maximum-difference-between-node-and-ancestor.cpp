
class Solution {
public:
    int ans = 0;
    
    int maxAncestorDiff(TreeNode* root) {

        h(root);
        return ans;
    }
    
    pair<int,int> h(TreeNode* r){
        int k = r->val;
        pair<int,int> a = {k,k} ,b= {k,k};
        
        if(r->left) 
            a = h(r->left);
        
        if(r->right)
            b = h(r->right);
        
        int x = a.first , y = b.first;
        int x1 = a.second , y1 = b.second;
        
        ans = max({ans , abs(r->val-x) , abs(r->val-y) });
        
        ans = max({ans , abs(r->val-x1) , abs(r->val-y1) });
        
        int ret1 = min({k,x,y});
        int ret2 = max({k,x1,y1});
        
        return {ret1,ret2};
        
    }
};