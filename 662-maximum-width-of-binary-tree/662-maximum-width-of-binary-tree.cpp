class Solution {
public:
    typedef unsigned long long int ull;
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)return 0;
        
        deque<unsigned long long> idx ; deque<TreeNode*> nodes;
        
        nodes.push_back(root); idx.push_back(0);
        
        unsigned long long ans = 0;
        while(nodes.size()>0){
            
            int n = nodes.size();
         
            if(idx[n-1] - idx[0]+1 > ans)
                ans = idx[n-1] - idx[0]+1 ;
            
            for(int i=0; i<n; i++){
                
                TreeNode* r = nodes.front();
                unsigned long long id = idx.front(); 
                
                nodes.pop_front();
                idx.pop_front();
                
                if(r->left){
                    nodes.push_back(r->left);
                    idx.push_back(2*id+1);
                }
                
                if(r->right){
                    nodes.push_back(r->right);
                    idx.push_back(2*id+2);
                }
                
            }
    
        }
        return ans;
    
    }
    
};