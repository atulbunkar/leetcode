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
      
        queue<TreeNode*> curr;   queue<TreeNode*> next;
        curr.push(root);
        vector<int> temp;
        int nodes = 0; int k = 0;
        
        while(!curr.empty()){
            TreeNode* t = curr.front(); curr.pop();
            
            temp.push_back(t->val);
            
            if(t->left)
                next.push(t->left);
            if(t->right)
                next.push(t->right);
            
            if(curr.empty()){
                curr.swap(next);    //swaps the elements of queue
                ans.push_back(temp);
                temp.clear();
            }
            
        }
        int c = 0;
        for(auto& x:ans){
            if(c%2 ==1)
                reverse(x.begin(),x.end());
            c++;
        }
        
        
        return ans;
    }
};