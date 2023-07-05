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
    TreeNode* buildBST(int &idx, vector<int> &preorder, int ub){
        if(idx== preorder.size() || preorder[idx]> ub)  return NULL;
        
        TreeNode* temp= new TreeNode(preorder[idx++]);
        
        temp->left= buildBST(idx, preorder, temp->val);
        // if in left we are not able to join the node we move to right
        
        temp->right= buildBST(idx, preorder, ub);
        
        return temp;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int idx=0;
        
        return buildBST(idx, preorder, INT_MAX);
    }
    
    
};