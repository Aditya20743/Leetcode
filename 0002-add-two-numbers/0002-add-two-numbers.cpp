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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* prev= dummy;
        int c=0;
        
        while(c || l1 || l2){
            int sum=0;
            if(l1){
                sum+= l1->val;
                l1= l1->next;
            }
            if(l2){
                sum+= l2->val;
                l2= l2->next;
            }
            if(c){
                sum+= c;
            }
            c= sum/10;
            ListNode* temp= new ListNode(sum%10);
            prev->next = temp;
            prev= temp;
            
        }
        
        return dummy->next;
    }
};