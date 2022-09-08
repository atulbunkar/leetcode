/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    
    TreeNode* lowestCommonAncestor(TreeNode* r, TreeNode* p, TreeNode* q) {
        
        if(r->val == p->val)return r;
        if(r->val ==q->val)return r;
        
        if(r->val > p->val and r->val < q->val)
            return r;
        
        if(r->val > q->val and r->val < p->val)
            return r;
        
        if(r->val > p->val and q->val < r->val)
            return lowestCommonAncestor(r->left , p,q);
        
        if(r->val < p->val and q->val > r->val)
            return lowestCommonAncestor(r->right , p,q);
        
        return NULL;
        
    }
};