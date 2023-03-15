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
    int height(TreeNode* t){
        if(!t)  return 0;
        return 1+max(height(t->left), height(t->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(!root)   return true;
        else if(abs(height(root->left)- height(root->right))>1 )    return false;
        else if(!isBalanced(root->right) || !isBalanced(root->left))    return false;
        return true;
    }
};