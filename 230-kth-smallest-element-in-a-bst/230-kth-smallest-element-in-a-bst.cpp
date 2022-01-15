
class Solution {
    int ans=0;
    int c = 0;
public:
    
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
    void dfs(TreeNode* root, int k){

        
        if(!root)return;
        
        dfs(root->left, k);
        c++;
        if(k==c and !ans)ans= root->val;
              
        dfs(root->right,k);
    }
};