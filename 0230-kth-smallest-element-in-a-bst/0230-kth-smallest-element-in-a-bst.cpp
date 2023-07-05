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
    void inorder(TreeNode* node, int &count, int &ans){
        if(!node){
            return;
        }
        inorder(node->left, count,ans);
        count-=1;
        if(count==0){
            ans= node->val;
            return ;
        }
        inorder(node->right,count,ans);
        
    }
    int kthSmallest(TreeNode* root, int k) {
        // inorder 
        int count=k;
        int ans;
        inorder(root, count, ans);
        return ans;
    }
};