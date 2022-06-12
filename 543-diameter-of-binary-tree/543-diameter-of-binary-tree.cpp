
class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        help(root);
       
        return ans;
    }
    
    int help(TreeNode* root){
        if(!root)return 0;
        
        if(!root->left and !root->right)return 1;
 
        int x = help(root->left) ;
        int y = help(root->right) ;
        
        ans = max(x+y,ans);
        return max(x,y)+1;
    }
    
    
};