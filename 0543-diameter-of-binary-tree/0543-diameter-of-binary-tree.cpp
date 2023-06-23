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
    int helper(TreeNode* node, int &maxi,int &ans){
        if(node==NULL)  return 0;
        
        int left_node= helper(node->left,maxi,ans);
        int right_node= helper(node->right,maxi,ans);
        
        ans =max(ans, left_node + right_node + 1);
        
        return max(left_node, right_node)+1;
 
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi=0 ,ans=0;
        
        if(root==NULL)  return 1;
        
        helper(root, maxi, ans);
    
        return ans-1;
    }
};