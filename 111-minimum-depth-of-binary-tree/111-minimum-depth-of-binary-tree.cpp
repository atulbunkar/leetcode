
class Solution {
public:
    int minDepth(TreeNode* root){
        if(!root)
            return 0;
        return  minDepth1(root,1);
    }
    int minDepth1(TreeNode* root,int h) {
        if(!root)
            return INT_MAX;
        if(!root->left&&!root->right)
            return h;
        return  min(minDepth1(root->left,h+1),minDepth1(root->right,h+1));
    }
    
};