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
        if(temp==NULL){
            return head;
        }
        int c=0;
        while(temp){
            temp=temp->next;
            c++;
        }
        c=c-n;
        temp= head;
        int k=0;
        if(k>c-1){
            head = head->next;
            return head;
        }
        if(k==c-1){
            temp->next= temp->next->next;
        }
        while(temp){
            temp=temp->next;
            k++;
            if(k== c-1){
                temp->next= temp->next->next;
            }
            
        }
        
        return head;
        
    }
};
// [1,2,3,4,5]
// 2
// [1]
// 1
// [1,2]
// 1