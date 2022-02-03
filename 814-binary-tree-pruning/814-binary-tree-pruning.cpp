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
    TreeNode* pruneTree(TreeNode* root) {
        if(!root)return root;
        
        if(!dfs(root->left)){
            root->left = NULL;
        }
        if(!dfs(root->right)){
            root->right = NULL;
        }
        
        pruneTree(root->left );
        pruneTree(root->right );
        
        if(!root->left and !root->right and root->val==0)return NULL;
        return root;
        
        
    }
    
    bool dfs(TreeNode* root){
        if(!root)return false;
        
        if(root->val == 1)return true;
        
        return dfs(root->left) || dfs(root->right);
  
    }
    
};