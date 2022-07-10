
class Solution {
public:
    int noneed = 3 , hascam =1, nocam=2; int ans =0;
    int minCameraCover(TreeNode* root) {
        if(!root->left and !root->right)return 1;
        
        if(dfs(root) == nocam)ans++;
        return ans;
    }
    
    int dfs(TreeNode* root){
            
        if(!root){
           return noneed;
        }
        
        if(!root->left and !root->right){
            return nocam;
        }
        
        int l = dfs(root->left);
        int r = dfs(root->right);
        
        if(l==nocam || r==nocam ){
            ans++;
            return hascam;
        }
        else if(l== noneed and r==noneed){
            return nocam;
        }
        
        else {
            return noneed;
        }
        
       
    }
};