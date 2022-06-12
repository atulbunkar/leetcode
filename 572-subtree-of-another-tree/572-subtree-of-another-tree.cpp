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
    bool isSubtree(TreeNode* root, TreeNode* sr) {
        if(!root || !sr)return false;
         
        
        return check(root,sr) || isSubtree(root->left, sr) || isSubtree(root->right,sr);
        
    }
    
    bool check(TreeNode* root, TreeNode* sr){
        
        if(!root and !sr)return true;
        
        if(!root || !sr)return false;
    
        if(root->val == sr->val){
            return check(root->left, sr->left) and check(root->right,sr->right);
        }
        return false;
    }
};