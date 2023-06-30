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
    int helper(TreeNode* temp){
        int ans=0;
        if(temp==NULL)  return 0;
        
        if(temp->left){
            ans=max(ans,helper(temp->left)+1);
        }
        if(temp->right){
            ans=max(ans,helper(temp->right)+1);
        }
        return ans;
        
    }
    int maxDepth(TreeNode* root) {
        if(!root)    return 0;
        return helper(root)+1;
    }
};