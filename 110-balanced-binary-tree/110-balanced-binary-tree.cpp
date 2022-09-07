
class Solution {
public:
    bool ans = 1;
    bool isBalanced(TreeNode* root) {
        
         help(root) ;
        return ans;
    }
    
    int help(TreeNode* r){
        
        if(!r)return 0;
        
        int x = help(r->left);
        int y = help(r->right);
        
        if(abs(x-y) >1)ans = 0;
        
        return max(x,y)+1;
        
        
    }
};