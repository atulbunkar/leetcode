
class Solution {
public:
    //TO do : recursive 
    TreeNode* trimBST(TreeNode* root, int L, int R) {
        

      while(root!=NULL )
        {
            if(root->val<L) { root = root->right; }
            else if(root->val > R) { root = root->left; }
          else break;
        }
        
        // temporary pointer for left and right subtree
        TreeNode *Ltemp = root;
        TreeNode *Rtemp = root;
        
        if(!root)return root;
        
        // remove the elements larger than L
        while(Ltemp->left)
        {
            if( (Ltemp->left->val)<L ) { Ltemp->left = Ltemp->left->right; }
            else { Ltemp = Ltemp->left; }
        }
         // remove the elements larger than R
        while(Rtemp->right)
        {
            if( (Rtemp->right->val)>R) { Rtemp->right = Rtemp->right->left; }
            else { Rtemp = Rtemp->right; }
        }

       
        return root;
    }
    
    
};