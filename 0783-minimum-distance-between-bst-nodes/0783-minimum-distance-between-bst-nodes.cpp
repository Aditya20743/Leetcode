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
    vector<int> v;
    int pre=-1,ans=INT_MAX;
    void preorder(TreeNode * root){
        if(!root){
            return ;
        }
        preorder(root->left);
        
        if(pre!=-1)
            ans = min(ans,root->val- pre);
        
        pre= root->val;
        preorder(root->right);
        return;
    }
    int minDiffInBST(TreeNode* root) {
        preorder(root);
        // int ans=INT_MAX;
        // for(int i=0;i<v.size()-1;i++){
        //     ans= min(ans, v[i+1]-v[i]);
        // }
        return ans;
    }
};