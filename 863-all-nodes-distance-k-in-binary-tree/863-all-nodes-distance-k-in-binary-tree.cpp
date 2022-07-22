/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
     map<TreeNode*,vector<TreeNode*>> adj;
    
  // int found=false ; vector<int> ans; 
    vector<int> distanceK(TreeNode* root, TreeNode* t, int k){
        
        vector<int> ans;  ans.clear();
       
        fill(root,NULL);
        
        queue<TreeNode*> q; set<int> vstd;
        vstd.insert(t->val);
        q.push(t); ans.push_back(t->val);
        
        while(k>0){
            int n = q.size(); ans.clear();
            for(int i=0;i<n;i++){
                TreeNode* x = q.front(); q.pop();
                for(auto& ney:adj[x]){
                   
                    if(vstd.find(ney->val) == vstd.end()){
                        ans.push_back(ney->val);
                        vstd.insert(ney->val);
                        q.push(ney);
                    }
                }
                
            }
            k--;
        }
        sort(ans.begin(),ans.end());
        
        return ans;
        
    }
    
     void fill(TreeNode* root, TreeNode* par){
        if(!root)return;
        
        if(par)
            adj[root].push_back(par);
        
        if(root->left)
            adj[root].push_back(root->left);
            
        if(root->right)
            adj[root].push_back(root->right);
            
        fill(root->left,root);
        fill(root->right,root);
    }
    
        
       
    
};