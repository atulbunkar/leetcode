
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        ListNode* curr = head;
        stack<pair<int,int>> st;
        int n=0;
        while(curr){
            n++;
            curr = curr->next;
        }
        vector<int> ans(n);
        
        curr = head; int i=0; ListNode* t = head;
        
        while(curr){
            while(!st.empty() and curr->val > st.top().first ){
                ans[st.top().second] = curr->val;  st.pop();
            }
            st.push(make_pair(curr->val,i));
            i++;
            curr= curr->next;
        }
        
        return ans;
    }
};