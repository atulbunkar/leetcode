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
    int diff = INT_MAX; int prev = -1;
    
    int getMinimumDifference(TreeNode* root) {
        if(!root)return 0;
        
        getMinimumDifference(root->left);
        
        if(prev>-1)
            diff = min(diff, abs(prev-root->val));
        
        prev = root->val;
        
        getMinimumDifference(root->right);
        
        return diff;
    }
    
    
};