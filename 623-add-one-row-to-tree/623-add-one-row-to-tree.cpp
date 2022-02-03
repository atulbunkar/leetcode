
class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int d) {
        TreeNode* t = new TreeNode(val);
        
        if(d==1){ 
            t->left = root;
            return t;
        }
        
        int i=1;
        queue<TreeNode*> q;
        q.push(root);
        
        
        while(true){
            int n = q.size();
            if(--d == 1){
                
                
                for(int i=0;i<n ;i++){
                    TreeNode* x = q.front(); q.pop();
                    
                    TreeNode* t1 = new TreeNode(val);
                    TreeNode* t2 = new TreeNode(val);
                    
                    if(x->left)
                        t1->left = x->left;
                    if(x->right)
                        t2->right = x->right;
                    
                    x->left = t1;
                    x->right = t2;
                    
                }
                break;
            }
            
            
            for(int i=0;i<n; i++){
                TreeNode* x = q.front(); q.pop();
                
                if(x->left)
                    q.push(x->left);
                if(x->right)
                    q.push(x->right);   
            }
        
        }
        

        return root;
    }
};