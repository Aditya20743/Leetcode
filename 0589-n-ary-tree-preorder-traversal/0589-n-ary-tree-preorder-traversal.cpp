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
    void helper(vector<int>&v ,Node* root){
        if(!root)    return;
        v.push_back(root->val);
        
        vector<Node*> c= root->children;
        for(Node* it: c){
            helper(v, it);
        }
        
    }
    vector<int> preorder(Node* root) {
        vector<int> v;
        helper(v, root);
        return v;
    }
};