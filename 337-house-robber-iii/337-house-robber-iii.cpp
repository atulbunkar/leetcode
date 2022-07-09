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
    
    
    int rob(TreeNode* root) {
        map<pair<TreeNode* , int>,int> mp;
        return dp(root,0 ,mp);
    }
    
    int dp(TreeNode* root, int rob ,map<pair<TreeNode* , int>,int>& mp){
        
        if(!root)return 0;
        
        auto it = mp.find({root,rob});
        if( it != mp.end())return it->second;
        
        if(rob)
            return mp[{root,rob}] = dp(root->left,0,mp) + dp(root->right,0,mp);
            
        else{
            return mp[{root,rob}] = max(dp(root->left,1,mp)+root->val+dp(root->right,1,mp) , dp(root->left,0,mp)+dp(root->right,0,mp));
           
        }
            
            
        
    }
};