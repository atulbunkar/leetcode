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
    void flatten(TreeNode* root) {
        if(!root)return;
        
        dfs(root);
        
        return ;
    }
    
    TreeNode* dfs(TreeNode* root){
        if(!root)return NULL;
        
        TreeNode* curr = root;
        TreeNode* temp = root->right;
   
        root->right = dfs(root->left );
        
        while(curr->right)curr = curr->right;
        
        curr->right = dfs(temp);
        root->left = NULL;
        return root;
        
    }
};