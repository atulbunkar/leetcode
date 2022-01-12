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
    bool isPalindrome(ListNode* head) {
        ListNode *slow=head,*fast=head , *prev = head;
       while(fast->next and fast->next->next){
           fast = fast->next->next;
           slow= slow->next;
       }
        ListNode* start = head , *curr = slow->next , *N = NULL , *d =NULL;
        
        while(curr){
            N = curr->next;
            curr->next=d;
            d=curr;
            curr=N;
        }
        slow->next=d;
        slow=slow->next;
        
        while(slow)
        {
            if(slow->val!=head->val)
            {
            return false;
                
            }
            
            slow=slow->next;
            head=head->next;
            
        }
        
        return 1;
    }
};