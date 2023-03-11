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
    void inorder(TreeNode* curr, vector<int>&ans){
        if(!curr)   return;
        
        inorder(curr->left,ans);
        ans.push_back(curr->val);
        inorder(curr->right,ans);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(!root)   return {};
        vector<int> ans;
        inorder(root,ans);
        return ans;
    }
};