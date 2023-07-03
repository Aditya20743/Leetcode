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
    
    int countNodes(TreeNode* root) {
        TreeNode* temp= root;
        int lh=0, rh=0;
        while(temp){
            temp=temp->left;
            lh++;
        }
        temp= root;
        while(temp){
            temp=temp->right;
            rh++;
        }
        
        if(lh==rh){
            return pow(2,lh)-1;
        }
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};