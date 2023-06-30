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
        if(node==NULL)  return 0;
        int left= 0,right=0;
        
        if(node->left){
            left= height(node->left);
        }
        if(node->right){
            right= height(node->right);
        }
        
        return max(left, right) + 1;
    }
    
    bool isBalanced(TreeNode* node) {
        int left=0, right=0;
        if(!node)   return true;
        
        if(node->left){
            left= height(node->left);
            if(isBalanced(node->left)==false){
                return false;
            }
        }
        if(node->right){
            right= height(node->right);
            if(isBalanced(node->right)==false){
                return false;
            }
        }
        if(abs(left- right)>1)  return false;
        
        
        return true;
    }
};