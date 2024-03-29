/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // general approach of BT can be applied
        if(!root){
            return root;
        }
        if(root == p || root == q){
            return root;
        }
        
        if(root->val > p->val && root->val > q->val){
            return lowestCommonAncestor(root->left, p ,q );
        }
        if(root->val < p->val && root->val < q->val){
            return lowestCommonAncestor(root->right, p ,q );
        }
        return root;
    }
};