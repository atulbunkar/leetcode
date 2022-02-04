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
    bool first = true;
    TreeNode* constructMaximumBinaryTree(vector<int>& nums , int i=0, int j=0) {
        
        if(first){
            j=nums.size()-1;
            first = false;
        }
        
        if(j<i)return NULL;
        
        
        int mx = nums[i];
        int idx=i ;
            
        for(int m=i; m<=j ;m++){
            if(nums[m] > mx){
                mx = nums[m];
                idx = m;
            }
        }
        
        TreeNode* t = new TreeNode(mx);
        
        t->left = constructMaximumBinaryTree(nums,i,idx-1);
        t->right = constructMaximumBinaryTree(nums,idx+1,j);
        
        return t;
    }
};