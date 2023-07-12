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
        
        if(!head || !head->next)   return true;
        
        ListNode* slow= head, *fast= head;
        int n=0;
        stack<ListNode*> st;
        
        while(fast && fast->next){
            st.push(slow);
            slow= slow->next;
            fast= fast->next->next;
            
        }
        // cout<<st.size()<<endl;
    
        while(slow){
            // cout<<st.top()->val<<" "<<slow->val<<endl;
            if(st.top()->val== slow->val){
                st.pop();
            }
            slow= slow->next;
        }
        // cout<<st.size()<<endl;
        return st.empty();
        
    }
};