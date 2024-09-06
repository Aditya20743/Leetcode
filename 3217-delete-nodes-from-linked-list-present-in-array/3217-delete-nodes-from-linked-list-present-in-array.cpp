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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* temp = new ListNode(-1);
        unordered_set<int> st;
        for(auto it: nums){
            st.insert(it);
        }
        ListNode* prev = temp;
        ListNode* curr = head;
        ListNode* modifiedHead = temp;
        
        while(curr){
            
            while(st.find(curr->val)!=st.end()){
                curr = curr->next;
                if(curr == NULL){
                    temp->next = NULL;
                    break;
                }
            }
            if(curr == NULL)    break;
            
            temp -> next = curr;
            temp = temp ->next;
            curr = curr->next;
        }
        return modifiedHead->next;
    }
};