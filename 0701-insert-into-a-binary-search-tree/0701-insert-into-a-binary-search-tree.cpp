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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode* temp= root;
        
        if(!temp){ 
            return new TreeNode(val);
        }
        
        while(temp){
            if(val > temp->val){
                if(temp->right){
                    temp=temp->right;
                }
                else{
                    temp ->right = new TreeNode(val);
                    break;
                }
            }
            if(val< temp->val){
                if(temp->left){
                    temp=temp->left;
                }
                else{
                    temp ->left = new TreeNode(val);
                    break;
                }
            }
        }
        
        return root;
    }
};