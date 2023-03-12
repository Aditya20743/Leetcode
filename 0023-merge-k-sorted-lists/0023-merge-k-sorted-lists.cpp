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
    struct cmp{
        bool operator()(ListNode* a,ListNode* b){
        return a->val > b->val;
        }
    };
    
        
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*> , cmp > pq;
        for(auto it: lists){
            if(it)
            pq.push(it);
        }
        if(pq.empty()){
            return NULL;
        }
        ListNode* head= pq.top();
        ListNode* start= head;
        pq.pop();
        if(head->next)
            pq.push(head->next);
        
        
        while(!pq.empty()){
            ListNode* top= pq.top();
            //ans.push_back(top->val);
            head->next = top;
            head= head->next;
            pq.pop();
            if(top->next)
                pq.push(top->next);
        }
        return start;
    }
};