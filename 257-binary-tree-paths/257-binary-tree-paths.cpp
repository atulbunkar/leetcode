
class Solution {
public:
    vector<string> ans;
    vector<string> binaryTreePaths(TreeNode* root) {
        
        if(!root)return ans;
        
        string temp = to_string(root->val);
        
        if(!root->left and !root->right)
        {
            ans.push_back(temp);
            return ans;
        }
        
        if(root->left)
            dfs(root->left,temp);
        if(root->right)
            dfs(root->right,temp);
        
        return ans;
        
    }
    
    void dfs(TreeNode* root , string temp ){
       
        temp += "->"; 
        temp += to_string(root->val);
        
         if(!root->left and !root->right){
            ans.push_back(temp);
            return;
        }
        
        if(root->left)
            dfs(root->left,temp);
        if(root->right)
            dfs(root->right,temp);
    }
};