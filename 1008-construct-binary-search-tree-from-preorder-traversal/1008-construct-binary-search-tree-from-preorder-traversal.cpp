
class Solution {
public:
    int i = 0;
    TreeNode* bstFromPreorder(vector<int>& p ,int val = INT_MAX) {
        
        if(i>=p.size() || p[i]>val)return NULL;
        
        auto t = new TreeNode(p[i++]);
        t->left = bstFromPreorder(p,t->val);
        t->right = bstFromPreorder(p,val);
        
        
        
        return t;
        
    }
};