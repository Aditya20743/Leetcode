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

// start->val + end->val
class Solution {
public:
    int pairSum(ListNode* head) {
        ListNode* slow= head->next;
        ListNode* fast= head->next->next; 
        
        int n=1;
        while(fast!= NULL){
            n++;
            slow=slow->next;
            fast=fast->next->next;
        }
        // slow ptr reached middle
        
        ListNode* prev= NULL, *curr= slow;
        
        while(slow!= NULL){
            slow= curr-> next;
            curr->next= prev;
            prev= curr;
            curr= slow;
        }
        int maxi= INT_MIN;
        
        while(n--){
            maxi= max(head->val + prev->val, maxi);
            head=head->next;
            prev=prev->next;
        }
        return maxi;
    }
};