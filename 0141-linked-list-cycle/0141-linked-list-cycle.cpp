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
    bool hasCycle(ListNode *head) {
        if(head== NULL) return false;
        
        else if(head->next== NULL)   return false;
        
        else if(head->next->next== NULL) return false;
        
        ListNode* slow= head->next;
        
        ListNode* fast= head->next->next;
        
        if(slow==NULL ||fast==NULL) return false;
        
        while(slow!= fast){
            if(slow==NULL || fast==NULL){
                return false;
            }
            slow= slow->next;
            if(fast->next== NULL)   return false;
            fast= fast->next->next;
        }
        
        return  true;
        // ListNode* temp= head;
        
        // while(temp!= NULL){
        //     if(vis.find(temp)!= vis.end()){
        //         return true;
        //     }
        //     else{
        //         vis.insert(temp);
        //     }
        //     temp= temp->next;
        // }
        // return false;
    }
};