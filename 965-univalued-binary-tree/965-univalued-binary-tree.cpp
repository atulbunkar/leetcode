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
    int r;  TreeNode* roo; 
    
    bool isUnivalTree(TreeNode* root) {
        r = root->val;
        
        if(root->val != r)return false;
        
        return ff(root);
    }
     
    bool ff(TreeNode* root){
        if(!root)return true;
        
        if(root->val != r){
            return false;   
        }
        
       return ff(root->left) and ff(root->right);
        
    }
    
    
};