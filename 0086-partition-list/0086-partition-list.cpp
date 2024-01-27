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
    ListNode* partition(ListNode* head, int x) {
        ListNode* left=NULL, *right=NULL, *temp=NULL, *start = NULL ;
        
        while(head!= NULL){
            if(head->val < x){
                if(!left){
                    left= head;
                    start= head;
                }
                else{
                    left->next= head;
                    left= head;
                }
            } 
            else{
                if(!right){
                    temp= head;
                    right= head;
                }
                else{
                    right->next= head;
                    right= head;
                }
            }
            // cout<<head->val<<" ";
            head= head->next;
            // cout<<1<<endl;
        }
        
        if(right!=NULL)
            
            right->next= NULL;
        
        if(left==NULL){
            return temp;
        }
        

        
        if(left!= NULL){
            left->next= temp;
            
        }
        
        if(right==NULL){
            left->next=NULL;
        }
        return start;
    }
};