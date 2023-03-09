/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head== NULL || head->next==NULL ||!head->next->next)   return NULL;
        
        ListNode* slow= head->next;
        ListNode* fast= head->next->next;
        
        
        while(slow!= fast){
            if(!slow->next  || !fast->next || !fast->next->next)    return NULL;
            slow= slow->next;
            fast= fast->next->next;
            //if(!slow || !fast)  return NULL;
        }
        slow= head;
        int idx=0;
        while(slow!=fast){
            slow= slow->next;
            fast=fast->next;
            idx++;
        }
        //cout<<idx<<" ";
        return slow;
    }
};