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
    string s = "";
    string tree2str(TreeNode* root) {
        dp(root);
        int n= s.size();
        return s.substr(0,n-1);
    }
    
    void dp(TreeNode* root){
        if(!root)return;
        
        s += to_string(root->val);
        if(root->left ){
            s+= "(";
            dp(root->left);
        }
        if(root->right and !root->left){
            s+= "()";
            s += "(";
            dp(root->right);
        }
        else if(root->right){
            s += "(";
            dp(root->right);
        }
        s+= ")";
            
    }
};