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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> t;
        if(!root)return ans;
       
        while(root || !t.empty()){
            while(root){
                ans.push_back(root->val);
                t.push(root->right);
                root = root->left;
            }
            root = t.top(); t.pop();
                
        }
        return ans;
        
    }
};