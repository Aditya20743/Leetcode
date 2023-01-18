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
    ListNode* reverse(ListNode* head,ListNode* pn){
        if(head){
            ListNode* temp=  reverse(head->next, head);
            head->next= pn;
            return temp;
        }
        else
            return pn;
    }
    ListNode* reverseList(ListNode* head) {
        return reverse(head,NULL);
    }
};