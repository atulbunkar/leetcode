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
    bool done;
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(!root){
            return new TreeNode(val);
        }
        done = false;
        fun(root,val);
        return root;
    }
    void fun(TreeNode* root, int val){
        if(!root || done)return ;
        
        if(root->val < val)
            fun(root->right,val);
        else if(root->val > val)
            fun(root->left,val);
        
        if(!done){
            TreeNode* neww  = new TreeNode(val);
            if(root->val < val )
            {
                root->right = neww;
            }
            else{
                root->left = neww;
            }
            done = true;
        }
            
    }
};