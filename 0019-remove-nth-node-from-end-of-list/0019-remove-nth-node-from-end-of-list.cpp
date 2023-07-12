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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp= head;
        int c=0;
        while(temp){
            temp=temp->next;
            c++;
        }
        
        if(c-n==0){
            return head->next;
        }
        temp=head;
        while(temp){
            if(c-n==1){
                break;
            }
            temp=temp->next;
            c--;
        }
        if(c==1){
            temp->next=NULL;
        }
        else
            temp->next=temp->next->next;
        
        return head;
    }
};