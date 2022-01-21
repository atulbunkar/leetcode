/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        
        rec(root);
        return root;
    }
    
    void rec(Node* root){
        if(!root)return ;
        Node* c = root;
        
        if(c->left)
            c->left->next = c->right;
        
        if(c->next and c->right){
            c->right->next = c->next->left;
        }
        
        rec(root->left);
        rec(root->right);
        
    }
};