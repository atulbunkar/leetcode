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
    int ans = INT_MIN;
    int maxPathSum(TreeNode* root) {
        
        help(root);
        return ans;
        
    }
    
    int help(TreeNode* root){
        if(!root)return 0;
        ans = max(ans,root->val);
        
        if(!root->left and !root->right)
        {
            return root->val;
        }
        
        int l =  help(root->left) ;
        int r =  help(root->right);
        
        if(l<0)l=0;
        if(r<0)r=0;
        
        ans = max(l+r+root->val , max(ans , max(l,r)+root->val) ) ;
        
        return  root->val +max(l,r);
    }
};