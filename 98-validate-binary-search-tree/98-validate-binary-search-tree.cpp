/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeN,ode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isValidBST(TreeNode* root,TreeNode *mini=NULL,TreeNode*maxi=NULL) {
        if(!root)return true;
        if(mini && root->val <= mini->val)
            return 0;
        if(maxi && root->val>=maxi->val)
           return 0;
        return isValidBST(root->left,mini,root)&&isValidBST(root->right,root,maxi);
    }
    
    
};