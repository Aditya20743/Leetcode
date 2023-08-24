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
    ListNode* rotateRight(ListNode* head, int k) {
        if(k==0 || !head || !head->next)    return head;
        ListNode* temp= head, *t=head;
        int n=1;
        while(temp->next){
            temp=temp->next;
            n++;
        }
        // linked to head 
        temp->next= head;

        k= k%n;
        k= n-k;
        
        temp = head;
        // cout<<k<<endl;
        while(--k){
            temp=temp->next;
        }
        t= temp->next;
        temp->next= NULL;
        
        return t;
    }
};