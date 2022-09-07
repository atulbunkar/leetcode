
class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        queue<TreeNode*>q;
        vector<int> ans;
        
        if(!root)return {};
        q.push(root);
        
        while(!q.empty()){
            
            int n = q.size();
            
            while(n--){
                
                TreeNode* r = q.front(); q.pop();
                
                if(r->left)
                    q.push(r->left);
                if(r->right)
                    q.push(r->right);
                
                if(n==0)ans.push_back(r->val);
            }
            
        }
        
        return ans;
        
    }
};