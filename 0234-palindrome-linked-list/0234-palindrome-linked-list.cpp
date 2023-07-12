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
    // 1 stack store first half then traverse and check with stack.top
    // 2 reverse linkedlist from mid then check from head and mid
    
    ListNode* reverse(ListNode* head, ListNode* prev){
        
        if(head){
            ListNode* temp= reverse(head->next, head);
            head->next= prev;
            
            return temp;
        }
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        
        if(!head || !head->next)   return true;
        
        
        
        ListNode* slow= head, *fast= head;
        
        while(fast && fast->next){
            slow= slow->next;
            fast= fast->next->next;
        }
        
        ListNode* mid= reverse(slow,NULL);
        
        while(mid ){
            if(mid->val != head->val){
                return false;
            }
            mid=mid->next;
            head= head->next;
        }
        return true;
    }
//         int n=0;
//         stack<ListNode*> st;
        
//         while(fast && fast->next){
//             st.push(slow);
//             slow= slow->next;
//             fast= fast->next->next;
            
//         }
//         // cout<<st.size()<<endl;
    
//         while(slow){
//             // cout<<st.top()->val<<" "<<slow->val<<endl;
//             if(st.top()->val== slow->val){
//                 st.pop();
//             }
//             slow= slow->next;
//         }
//         // cout<<st.size()<<endl;
//         return st.empty();
        
//     }
};