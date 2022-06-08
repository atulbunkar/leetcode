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
    ListNode* oddEvenList(ListNode* head) {
        if(!head)return NULL;
        if(!head->next)return head;
        
        ListNode* even = head->next ;  ListNode* curr = head; ListNode* temp = even;
        
        while(curr and curr->next){
            temp = curr->next;
           
            
            curr->next = curr->next->next;
            if(curr->next)
            {
                temp->next = curr->next->next;
            }
            else
                break;
            
            curr = curr->next;
           
        
        }
        curr->next = even;
        return head;
        
        
    }
};