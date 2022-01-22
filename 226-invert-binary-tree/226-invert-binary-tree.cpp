/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root)return root;
        
        if(!root->left and !root->right)
            return root;
        
        dp(root);
        
        return root;
    }
    
    void dp(TreeNode* r){
        if(!r)return;
        
        // TreeNode* t = r->left;
        // r->left = r->right;
        // r->right = t;
        
        swap(r->left,r->right);
        
        dp(r->left);
        dp(r->right);
        

    }
};