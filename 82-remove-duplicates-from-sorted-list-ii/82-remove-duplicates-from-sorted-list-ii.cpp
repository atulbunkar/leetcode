/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
       
        
        if(!head || !head->next)return head;
         int temp = head->val;
        
        //Adding a new node at start of head. and making that new head.
        ListNode* prev = new ListNode(-1);
        prev->next = head;
        
        head = prev; int flag = 0;
        
        ListNode* curr = head->next ;prev = head ;
        
        while(curr){
            temp = curr->val;
            
            flag = 0;
            
            while(curr->next and temp == curr->next->val){
                
                prev->next = curr->next;
                curr = curr->next; 
                flag = 1;
            }
           
                
           if(flag){
               prev->next = curr->next;
               curr = prev->next;
           }
           else{
               prev = curr;
               curr = curr->next;
           } 
            
        }
        
        return head->next;
        
    }
};