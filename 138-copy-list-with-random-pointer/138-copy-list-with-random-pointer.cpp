
class Solution {
public:
    void printll(Node* head){
        Node* curr= head;
        while(curr){
            cout<< curr->val << " ";
            curr = curr->next;
        }
    }
    
public:
    Node* copyRandomList(Node* head) {
        Node* curr = head, *next;
        
        if(!head)return head;
        
        //making one chain of og and copy
        while(curr){                
            next = curr->next;
            
            Node* copy = new Node(curr->val);
            
            curr->next = copy;
            copy->next = next;
            
            curr = next ;
        }
      
        //creating random ptr of copy nodes
        curr = head;
        while(curr){
            next = curr->next->next;
            
            if(curr->random){
                curr->next->random = curr->random->next;
            }
            curr = next;
        }
        //Separating og and copy nodes
        
        Node* pseudohead = new Node(-1);
        curr = head ;Node* copy = pseudohead ; 
        
        while(curr){
            next = curr->next->next;
            
            copy->next = curr->next;
            copy = copy->next;
            
            curr->next = next;
            curr = next;
        }
        
        
        return pseudohead->next;
    }
};