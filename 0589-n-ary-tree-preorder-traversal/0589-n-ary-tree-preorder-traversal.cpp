/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
//     void helper(Node* root, vector<int>&ans){
//         if(!root)   return ;
        
//     }
    
    vector<int> preorder(Node* root) {
        vector<int> ans;
        // helper(root,ans);
        // return ans;
        if(!root)   return ans;
        stack<Node*> st;
        st.push(root);
        
        while(!st.empty()){
            Node* t= st.top();
            ans.push_back(t->val);
            st.pop();
            vector<Node*>  c= t->children;
            int n=c.size();
            for(int i=n-1;i>=0;i--){
                
                if(c[i]){
                    st.push(c[i]);
                }
            }
            
        }
        return ans;
        
    }
};