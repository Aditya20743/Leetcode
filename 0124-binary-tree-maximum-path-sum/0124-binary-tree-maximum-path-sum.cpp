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
    int maxi=INT_MIN;
    
    int sum(TreeNode* t){
        if(!t)  return 0;
        
        return max(t->val+max(sum(t->left), max(sum(t->right),0)),0);
    }
    int maxPathSum(TreeNode* root) {
        if(!root)   return 0;
        
        int ls= sum(root->left);
        int rs= sum(root->right);
        
        maxi=max(maxi,root->val + max(ls+rs,max(ls,rs)));
        
        maxPathSum(root->left);
        maxPathSum(root->right);
        
        return maxi;
    }
};