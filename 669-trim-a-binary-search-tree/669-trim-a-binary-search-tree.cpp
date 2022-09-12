
class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        
        if(!root)return NULL;
        
        if(low>root->val)
            return trimBST(root->right,low,high);
        
        if(high < root->val)
            return trimBST(root->left,low,high);
        
        root->left = trimBST(root->left,low,high);
        root->right =   trimBST(root->right,low,high);
        
        return root;
        
    }
};