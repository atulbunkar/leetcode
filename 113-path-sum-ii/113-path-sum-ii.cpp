
class Solution {
public:
    vector<vector<int>> ans; 
    vector<vector<int>> pathSum(TreeNode* root, int t) {
        vector<int> temp;
        if(!root)return ans;
        
        //temp.push_back(root->val);
        help(root,t,temp);
        return ans;
    }
    void help(TreeNode* root, int t, vector<int> temp) {
        if(!root)return ;
        
        temp.push_back(root->val);
        
        if(root->val == t and !root->left and !root->right){
            ans.push_back(temp);
            return;
        }
        
        help(root->left,t-root->val,temp);
        help(root->right,t-root->val,temp);
    }
};