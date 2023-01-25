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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.size()==0) return NULL;
        else if(lists.size()==1 && lists[0]==NULL)  return NULL; 
        
        priority_queue< int> mh;
        for(int i=0;i<lists.size();i++){
            ListNode* temp= lists[i];
            while(temp){
                mh.push(temp->val);
                temp= temp->next;
            }
            // for(int j=0;j<lists[i].size();j++){
            //     mh.push(list[i][j]->val);
            // }
        }
        int l= mh.size()-1;
        vector<int> v(mh.size());
        while(!mh.empty()){
            v[l--]= mh.top();
            mh.pop();
        }
        if(v.size()>=2){
        ListNode* h= new ListNode(v[0]);
        ListNode* t= new ListNode(v[1]);
        h->next= t;
        int i=2;
        while(i!= v.size()){
            ListNode* x= new ListNode(v[i]);
            t->next= x;
            t=t->next;
            i++;
        }
            
        t->next= NULL;
        return h;
        }
        else if(v.size()==1){
            ListNode* h= new ListNode(v[0]);
            h->next= NULL;
            return h;
        }
        return NULL;
        
        
        
    }
};