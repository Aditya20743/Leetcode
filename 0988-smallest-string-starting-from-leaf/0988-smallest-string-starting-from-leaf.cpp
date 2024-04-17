/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void traversal(TreeNode*node, vector<string>&store,string curr){
        if(!node){
            return ;
        }
        char x= node->val+'a';
        curr= x+curr;
        if(!node->left && !node->right){
            store.push_back(curr);
            return;
        }
        
        traversal(node->left, store, curr);
        traversal(node->right, store,curr);
    }
    
    string smallestFromLeaf(TreeNode* root) {
        vector<string> store;
        string curr="";
        traversal(root, store, curr);
        sort(store.begin(),store.end());
        return store[0];
    }
};