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
    vector<int> bst;
    
    void recoverTree(TreeNode* root) {
        if(!root)return ;
        
        bt(root);
        
        int l=-1,r=-1;
        for(int i=0;i<bst.size()-1;i++)
        {
            if(bst[i+1]<bst[i]){
                l = bst[i];
                break;
            }
        }
        
        for(int i=bst.size()-1; i>0;i--)
        {
            if(bst[i-1]>bst[i]){
                r = bst[i];
                break;
            }
        }
       // cout<< l << " "<<r;
        if(l==-1 and r==-1)return;
        
        swapp(root,l,r);
    
    }
    
    void bt(TreeNode* root){
        if(!root)return ;
         bt(root->left);
        bst.push_back(root->val);
        bt(root->right);
        
    }
    
    void swapp(TreeNode* ru,int l, int r){
        if(!ru)return;
        
        if(ru->val==l)ru->val=r;
        else if(ru->val==r)ru->val=l;
        
        swapp(ru->left,l,r);
        swapp(ru->right,l,r);
    }
};