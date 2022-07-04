/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;
        
        unordered_map<int,Node*> mp;
        
        return clone(node,mp);
    }
    
    Node* clone(Node* n ,  unordered_map<int,Node*>& mp){
        Node* tmp = new Node;
        tmp->val = n->val;
        vector<Node*> nb ;
        mp[n->val] = tmp;
        
        for(auto x: n->neighbors){
            if(mp[x->val])nb.push_back(mp[x->val]);
            
            else nb.push_back( clone(x,mp) );
        }
        tmp->neighbors = nb;
        return tmp;
    }
};