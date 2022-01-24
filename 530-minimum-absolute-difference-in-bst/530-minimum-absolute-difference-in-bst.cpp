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
    int diff = INT_MAX;
    int getMinimumDifference(TreeNode* root) {
        
        stack<TreeNode*> st;
        st.push(root);
        
        while(!st.empty()){
            root = st.top(); st.pop();
            dif(root);
            if(root->left)st.push(root->left);
            if(root->right)st.push(root->right);
            
        }
       return diff;
        
    }
    
    
    void dif(TreeNode* root){
         diff = min(diff, abs(root->val - getpred(root)));
         diff = min(diff , abs(root->val - getsucc(root)));     
    }
    
    int getpred(TreeNode* root){
        if(!root->left)return INT_MAX;
        
        root = root->left;
        while(root->right){
            root = root->right;
        }
        return root->val;
    }
    int getsucc(TreeNode* root){
        if(!root->right)return INT_MAX;
        
        root = root->right;
        while(root->left){
            root = root->left;
        }
        return root->val;
    }
};