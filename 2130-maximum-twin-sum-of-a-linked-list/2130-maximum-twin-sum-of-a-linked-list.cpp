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
    int pairSum(ListNode* head) {
        ListNode* temp= new ListNode(-1);
        ListNode* curr= head; 
        temp->next= curr;
        
        vector<int> v;
        
        while(curr){
            v.push_back(curr->val);
            curr= curr->next;
        }
        int maxi=INT_MIN;
        
        for(int i=0;i<=v.size()/2 - 1;i++){
            maxi= max(v[i]+ v[v.size()-1-i] , maxi);
        }
        return maxi;
    }
};