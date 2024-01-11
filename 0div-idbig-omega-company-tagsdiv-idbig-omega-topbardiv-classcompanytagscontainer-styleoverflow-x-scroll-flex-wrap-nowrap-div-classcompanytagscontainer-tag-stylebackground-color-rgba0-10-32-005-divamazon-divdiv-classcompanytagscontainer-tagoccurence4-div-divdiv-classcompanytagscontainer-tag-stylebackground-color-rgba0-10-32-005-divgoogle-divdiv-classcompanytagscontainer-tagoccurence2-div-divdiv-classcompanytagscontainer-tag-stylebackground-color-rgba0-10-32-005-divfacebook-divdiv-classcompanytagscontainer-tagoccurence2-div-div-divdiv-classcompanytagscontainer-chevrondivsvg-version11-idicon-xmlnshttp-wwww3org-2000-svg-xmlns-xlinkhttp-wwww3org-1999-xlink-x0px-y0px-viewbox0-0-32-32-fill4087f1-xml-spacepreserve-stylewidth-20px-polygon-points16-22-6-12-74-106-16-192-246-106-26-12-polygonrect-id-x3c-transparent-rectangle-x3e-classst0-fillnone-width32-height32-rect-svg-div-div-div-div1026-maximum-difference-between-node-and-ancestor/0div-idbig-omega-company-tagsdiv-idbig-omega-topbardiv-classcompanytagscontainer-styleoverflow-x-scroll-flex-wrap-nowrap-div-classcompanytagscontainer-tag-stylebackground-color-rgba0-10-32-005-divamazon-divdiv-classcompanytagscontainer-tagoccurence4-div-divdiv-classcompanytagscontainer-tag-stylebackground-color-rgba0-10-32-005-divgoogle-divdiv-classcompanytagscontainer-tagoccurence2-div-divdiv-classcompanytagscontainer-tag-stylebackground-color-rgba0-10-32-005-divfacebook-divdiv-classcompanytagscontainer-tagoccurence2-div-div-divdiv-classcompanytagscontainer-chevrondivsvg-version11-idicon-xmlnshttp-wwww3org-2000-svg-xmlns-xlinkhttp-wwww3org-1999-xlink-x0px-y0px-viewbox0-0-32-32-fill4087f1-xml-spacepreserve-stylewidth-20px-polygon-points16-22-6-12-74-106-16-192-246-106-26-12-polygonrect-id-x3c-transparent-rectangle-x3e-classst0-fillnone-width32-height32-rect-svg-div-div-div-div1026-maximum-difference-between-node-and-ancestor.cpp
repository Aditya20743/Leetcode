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
    void helper(TreeNode* r, int mini,int maxi, int&ans){
        ans= max(ans, max(maxi- r->val, r->val-mini));
        
        if(r->left ){
            ans= max(ans, max(maxi- r->val, r->val- mini));
            maxi= max(maxi, r->val);
            mini= min(mini, r->val);
            helper(r->left, mini, maxi, ans);
            
        }
        if(r->right ){
            ans= max(ans, max(maxi- r->val, r->val- mini));
            mini= min(mini, r->val);
            maxi= max(maxi, r->val);
            helper(r->right, mini,maxi, ans);   
        }
        
    }
    
    int maxAncestorDiff(TreeNode* root) {
        int ans=0, mini=INT_MAX, maxi=-1;
        
        helper(root, root->val,root->val,ans);
        
        return ans;
    }
};