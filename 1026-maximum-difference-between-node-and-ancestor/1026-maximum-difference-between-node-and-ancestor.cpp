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
    int ans = -1;
    int maxAncestorDiff(TreeNode* root) {
        maxdfs(root);
        mindfs(root);
        return ans;
    }
    
    int maxdfs(TreeNode* root){
        if(!root)return -1;
        if(!root->left and !root->right)return root->val;
         int x=-1,y=-1;
        
         x = maxdfs(root->left) ; 
         y = maxdfs(root->right) ; 
            
         x = max(x,y);
        
         if(x>-1)ans = max(ans , abs(root->val - x));
        
         return max(root->val , x);
    }
    
     int mindfs(TreeNode* root){
        if(!root)return INT_MAX;
        if(!root->left and !root->right)return root->val;
         int x=-1,y=-1;
        
         x = mindfs(root->left) ; 
         y = mindfs(root->right) ; 
            
         x = min(x,y);
        
         if(x<INT_MAX)ans = max(ans , abs(root->val - x));
        
         return min(root->val , x);
    }
    
    
};