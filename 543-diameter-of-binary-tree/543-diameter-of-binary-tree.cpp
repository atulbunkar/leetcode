
class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        help(root);
        return ans;
    }
    
    int help(TreeNode* root){
        if(!root)return 0;
        
        int l =  help(root->left) ;
        int r = help(root->right);
        
        ans = max(ans , l+r);
        
        return  max( l+1 , r+1);
    }
};