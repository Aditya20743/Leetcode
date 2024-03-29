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
//     void inorder_traversal(TreeNode* node, vector<int>& inorder){
//         if(!node){
//             return ;
//         }
//         inorder_traversal(node->left, inorder);
//         inorder.push_back(node->val);
//         inorder_traversal(node->right,inorder);
//     }
    bool check(TreeNode* node, long long min, long long max){
        if(!node)   return true;
        
        if(!(node->val > min && node->val < max)){
            return false;
        }
        
        return check(node->left, min, node->val)&&check(node->right, node->val, max);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root==NULL)  return true;
        
        return check(root,LONG_MIN, LONG_MAX);
    }
};