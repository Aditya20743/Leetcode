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
    ListNode* reverse(ListNode* head, ListNode* prev){
        
        if(head){
            ListNode* temp= reverse(head->next, head);
            
            head->next= prev;
            
            return temp;
        }
        return prev;
    }
    
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return head;
        }
        // return reverse(head, NULL);
        
        ListNode* temp= head;
        ListNode* prev= NULL;
        ListNode* nxt= NULL;
        
        while(temp){
            nxt= temp->next;
            
            temp->next= prev;
            
            prev= temp;
            temp=nxt;
        }
        
        
        return prev;
        
    }
};