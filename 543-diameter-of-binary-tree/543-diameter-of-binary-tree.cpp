
class Solution {
public:
    int ans = 0;
    int diameterOfBinaryTree(TreeNode* root) {
        help(root);
        return ans;
    }
    
    int help(TreeNode* root){
        if(!root)return -1;
        int lh = 1+help(root->left);
        int rh = 1+help(root->right);
        
     
        ans = max(ans, lh+rh);
        //cout<< "root : "<< root->val << " : " << lh << rh<<endl;
        return max(lh,rh);
    }
};