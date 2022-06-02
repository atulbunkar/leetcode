class Solution {
    int ans=0;
    bool flag = false;
public:
    
    int kthSmallest(TreeNode* root, int k) {
        dfs(root,k);
        return ans;
    }
    
    void dfs(TreeNode* root, int& k){
        if(!root || flag)return ;
        
        dfs(root->left,k);
        
        k--;
        if(k<0)return;
        
        if(k==0){
            ans = root->val;
            flag =true;
        }
        dfs(root->right,k);
        

        
    }
    
              
     
    
};