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
    ListNode* reverseList(ListNode* head) {
        ListNode* h , *nxt , *prev, *temp;
        if(!head)return head;
        
        h = head ; nxt = head->next;
        prev = NULL ;
        
        
        while(nxt){
            temp = nxt->next;
            nxt->next = h;
            h->next = prev;
            
            prev = h;
            h= nxt;
            nxt = temp; 
        }
        
        return h;
        
    }
};