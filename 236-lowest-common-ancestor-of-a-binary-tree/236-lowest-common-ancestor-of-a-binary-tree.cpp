/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* ans = NULL;
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        bool l=false,r=false;
        
        if(!root)return NULL;
        
        if(find(root->left,p) and find(root->left,q))
           return lowestCommonAncestor(root->left,p,q);
        else if(find(root->right,p) and find(root->right,q)){
            return lowestCommonAncestor(root->right,p,q);
        }
        
        return root;
        
        
        
    }
    
    bool find(TreeNode* root, TreeNode* p){
        
        if(!root)return false;
        
        if(root==p)return true;
        
        return find(root->left,p) || find(root->right,p);
        
    }
};