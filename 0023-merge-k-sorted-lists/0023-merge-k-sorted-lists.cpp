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
    // IN min heap we use to write greater while declaring so greater cmp
    struct cmp{
        bool operator() (ListNode* a, ListNode* b){
            return a->val > b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , cmp > maxheap;
        ListNode* dummy=new ListNode(-1);
        ListNode* tail= dummy;
        
        for(int i=0;i<lists.size();i++){
            if(lists[i]!= NULL)
            maxheap.push(lists[i]);
        }
        
        while(!maxheap.empty()){
            ListNode* temp= maxheap.top();
            tail->next= temp;
            tail= temp;
            maxheap.pop();
            if(temp->next)  maxheap.push(temp->next);
        }
        return dummy->next;
        
    }
};