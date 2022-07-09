
class Solution {
public:
    map<pair<TreeNode*, ListNode*> , int> mem;
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root and !head)return true;
        if(!root)return false;
        
        return help(head,root) || isSubPath(head,root->left) || isSubPath(head,root->right);
        
    }
    
    bool help(ListNode* head, TreeNode* root){
        if(!head)return true;
        if(!root)return false;
        
        if(mem.find({root,head}) != mem.end())return mem[{root,head}];
        
        if(root->val != head->val)return false;
        
        return mem[{root,head}] = help(head->next,  root->left) 
            || help(head->next, root->right) ;
    }
};