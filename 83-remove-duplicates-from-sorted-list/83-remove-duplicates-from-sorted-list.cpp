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
        ListNode* curr = head;
        if(!head || !head->next)return head;
        
        
       // curr= curr->next;
        
        while(curr and curr->next){
            
            int temp = curr->val;
            
            while(curr->next and curr->next->val == temp){
                curr->next = curr->next->next;
            }
            curr = curr->next;
            
        }
        return head;
        
    }
};