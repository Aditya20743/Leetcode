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
    
    // dir=0 left dir=1 right dir=-1 start
    int maxi=0;
    void helper(TreeNode* root, int count, int dir){
        maxi= max(maxi,count);
        if(!root)   return;
        
        if(root->left){
            if(dir== 0){
                helper(root->left, 1, 0);
            }
            else helper(root->left, count+1, 0);
        }
        
        if(root->right){
            if(dir== 1){
                helper(root->right, 1, 1);
            }
            else helper(root->right, count+1, 1);
        }
    }
    int longestZigZag(TreeNode* root) {
        int count=0, dir=-1;
        helper(root,count,dir);
        return maxi;
    }
};