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
    //Note : head is guaranteed to be not null, so it contains at least one node.
    ListNode* HeadNode;
    Solution(ListNode* head) {
       HeadNode = head;
    }
    // Reservoir sampling
    //returns value of a random node
    int getRandom() {
        int res, len = 1;
        ListNode* x = HeadNode;
        while(x){
            if(rand() % len == 0){
                res = x->val;
            }
            len++;
            x = x->next;
        }
        return res;
    }
};
// class Solution {
// public:
//     vector<int> store;
//     Solution(ListNode* head) {
//         ListNode* temp=head;
//         while(temp){
//             store.push_back(temp->val);
//             temp=temp->next;
//         }
//     }
    
//     int getRandom() {
//         long long lb=0, ub= store.size()-1;
//         long long x=(rand()%(ub-lb+1)+lb);
//         return store[x];
//     }
// };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */