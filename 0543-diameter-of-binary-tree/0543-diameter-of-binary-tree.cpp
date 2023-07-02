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
    int height(TreeNode* node){
        if(!node)   return 0;
        int lh=0,rh=0;
        if(node->left){
            lh= height(node->left);
        }
        if(node->right){
            rh= height(node->right);
        }
        return max(lh,rh)+1;
    }
    void helper(TreeNode* root, int &maxi){
        if(!root)   return ;
        
        maxi= max(maxi, height(root->left)+height(root->right)+1);
        
        helper(root->left, maxi);
        helper(root->right,maxi);
        
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0;
        if(!root)   return 0;
        
        helper(root,maxi);
        
        return maxi-1;
    }
};