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
    void reorderList(ListNode* head) {
        if(!head)return ;
        
        stack<ListNode*> st; st.push(head);
        ListNode* t = head;
        
        if(!head->next)return;
        
        while(t){
            st.push(t); t = t->next;
        }
        
        t = head;
        ListNode* t1 = head->next;  ListNode* last; vector<ListNode*> v;
        
        while(t and t1){
           
            if(st.empty())last = NULL;
            else {
                last =  st.top(); st.pop();
                 v.push_back(last);
            }
            
            t->next = last;
            last->next = t1;
            
            if(find(v.begin(),v.end(),t1->next) != v.end())break;
         
            t = t1;
            t1 = t1->next;
            //cout<< t->val << " " << t1->val<< " ";
        }
      
        t1->next = NULL;
        
        
        return ;
    }
    
    
    
};