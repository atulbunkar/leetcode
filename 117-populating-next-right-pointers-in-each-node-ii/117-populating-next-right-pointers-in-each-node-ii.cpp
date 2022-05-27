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
            
        if(root->left){
            if(root->right)
                root->left->next = root->right;
            else{
                root->left->next = nxt(root->next);
            }
        }
        
        if(root->right){
            root->right->next = nxt(root->next);
        }
  
        connect(root->right);
        connect(root->left);

        return root;
    }
    
    
    Node* nxt(Node* node){
        
        if(!node)return NULL;
        if(node->left)return node->left;
        else if(node->right)return node->right;
        else return nxt(node->next);
        
    }
};