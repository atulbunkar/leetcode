
class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        help(root,0);
        return ans;
    }
    
    int help(TreeNode* root, int val){
        if(!root)return 0;
        
        int l =  help(root->left, val+1) ;
        int r = help(root->right,val+1);
        
        ans = max(ans , l+r);
        
        return 1+ max( l , r);
    }
};