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
    
    vector<string> v;
    string smallestFromLeaf(TreeNode* root) {
      
        dp(root,"");
        
        sort(v.begin(),v.end());
        
        return v[0];
    }
    
    void dp(TreeNode* root, string s){
        if(!root)return;
        
        s = char(root->val+'a')+s;
        
        if(!root->left and !root->right){
            v.push_back(s);
            return;
        }
        
        dp(root->left, s);
        dp(root->right,s);
        
        
    }
    
    
};