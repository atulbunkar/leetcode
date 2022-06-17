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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* ans = new ListNode(0);
        ListNode* temp = ans, *t;
        
        multiset<int> s;
        
        for(auto x:lists){
            t = x;
            while(t)
            {
                s.insert(t->val);
                t= t->next;
            }
        }
        
        
        for(auto it = s.begin(); it != s.end(); it++){
            temp->next = new ListNode(*it);
            temp = temp->next;
        }
        
        return ans->next;
    }
};