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
    void right(TreeNode* root,vector<int>&v){
        if(!root)   {v.push_back(111);  return;}
        v.push_back(root->val);
    
        right(root->right, v);
        left(root->left, v);
        
    }
    void left(TreeNode* root,vector<int>&v){
        if(!root)   {v.push_back(111);  return;}
        v.push_back(root->val);
        
        left(root->left, v);
        right(root->right, v);
        
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> leftside, rightside;
        if(root){
            left(root,leftside);
            right(root,rightside);
        }
        return leftside == rightside ;
    }
};