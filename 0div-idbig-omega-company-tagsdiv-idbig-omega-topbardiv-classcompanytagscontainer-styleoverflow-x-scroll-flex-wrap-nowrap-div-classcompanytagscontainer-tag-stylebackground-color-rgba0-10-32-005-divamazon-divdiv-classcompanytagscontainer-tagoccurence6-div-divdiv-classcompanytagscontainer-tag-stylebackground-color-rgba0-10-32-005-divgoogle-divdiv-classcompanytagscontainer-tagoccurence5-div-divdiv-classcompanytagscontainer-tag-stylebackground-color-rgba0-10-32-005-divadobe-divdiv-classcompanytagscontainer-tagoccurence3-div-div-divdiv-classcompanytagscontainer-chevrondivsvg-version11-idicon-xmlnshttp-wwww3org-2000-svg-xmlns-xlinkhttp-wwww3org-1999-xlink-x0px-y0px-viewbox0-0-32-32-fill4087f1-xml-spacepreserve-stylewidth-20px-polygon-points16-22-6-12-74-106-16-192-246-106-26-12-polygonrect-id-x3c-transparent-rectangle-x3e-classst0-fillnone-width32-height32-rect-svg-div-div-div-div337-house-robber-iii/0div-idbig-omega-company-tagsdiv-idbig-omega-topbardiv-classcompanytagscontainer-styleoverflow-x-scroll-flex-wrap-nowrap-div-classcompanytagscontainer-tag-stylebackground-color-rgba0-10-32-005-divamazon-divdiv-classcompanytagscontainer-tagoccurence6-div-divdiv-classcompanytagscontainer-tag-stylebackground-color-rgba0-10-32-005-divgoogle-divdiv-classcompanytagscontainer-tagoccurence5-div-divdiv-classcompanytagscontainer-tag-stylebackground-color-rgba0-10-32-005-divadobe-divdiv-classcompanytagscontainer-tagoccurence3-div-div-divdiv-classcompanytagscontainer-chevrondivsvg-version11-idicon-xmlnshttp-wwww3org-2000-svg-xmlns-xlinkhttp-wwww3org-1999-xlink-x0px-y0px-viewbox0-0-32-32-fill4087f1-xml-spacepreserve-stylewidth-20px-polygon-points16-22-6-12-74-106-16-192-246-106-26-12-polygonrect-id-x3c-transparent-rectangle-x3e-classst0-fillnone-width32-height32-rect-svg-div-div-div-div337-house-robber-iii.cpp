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
    int helper(TreeNode* node, int i,unordered_map<TreeNode*, unordered_map<int,int>>&mp){
        if(node== NULL) return 0;
        
        if(mp[node][i])     return mp[node][i];
        if(i==0){
            int l=0;
            int r=0;
            if(node->left){
                l= max(helper(node->left,0,mp) ,
                       helper(node->left,1,mp)+node->left->val);
            }
            if(node->right){
                r= max(helper(node->right,0,mp) ,
                       helper(node->right,1,mp)+node->right->val);
            }
            return mp[node][i]=l+r;
        }
        else{
            int l=0;
            int r=0;
            if(node->left){
                l= helper(node->left,0,mp);
            }
            if(node->right){
                r= helper(node->right,0,mp);
            }
            return mp[node][i]=l+r;
        }
        return 0;
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*,unordered_map<int,int>> mp;
        int not_take= helper(root,0,mp);
        int take= helper(root,1,mp)+ root->val;
        
        return max(take, not_take);
    }
};