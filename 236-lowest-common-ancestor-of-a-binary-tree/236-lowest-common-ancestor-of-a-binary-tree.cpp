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
        
        if(root ==p || root == q){
            ans = root;
            return ans;
        }
        
        l = find(root->left,p);
        r = find(root->right,q);
        
        if(l and r){
            ans = root;
            return ans;}
        
        l = find(root->left,q);
        r = find(root->right,p);
        
         if(l and r){
            ans = root;
            return ans;
         }
        
        if(!ans)
        lowestCommonAncestor(root->left,p,q);
        
        if(!ans)
        lowestCommonAncestor(root->right,p,q);
        
        return ans;
        
    }
    
    bool find(TreeNode* root, TreeNode* p){
        
        if(!root)return false;
        
        if(root==p)return true;
        
        return find(root->left,p) || find(root->right,p);
        
    }
};