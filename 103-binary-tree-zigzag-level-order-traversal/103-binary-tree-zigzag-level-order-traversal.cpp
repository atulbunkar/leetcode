/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
          vector<vector<int>> ans;
        if(!root)return ans;
      
        queue<TreeNode*> curr;   stack<TreeNode*> next;
        curr.push(root);
        vector<int> temp;
        int nodes = 0; int lvl = 0; 
        
        while(!curr.empty()){
            TreeNode* t = curr.front(); curr.pop();
            
            temp.push_back(t->val);
            
            if(lvl%2==0){
                if(t->left)
                    next.push(t->left);
                if(t->right)
                    next.push(t->right);
            }
            else{
                 if(t->right)
                    next.push(t->right);
                if(t->left)
                    next.push(t->left);
            }
            
            if(curr.empty()){
                lvl++;
                while(!next.empty()){
                    TreeNode* n = next.top(); next.pop();
                    curr.push(n);
                }
                ans.push_back(temp);
                temp.clear();
            }
            
        }
        
        
        
        return ans;
    }
};