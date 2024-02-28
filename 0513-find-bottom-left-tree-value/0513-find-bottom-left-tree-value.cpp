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
    void helper(int i, TreeNode*node, unordered_map<int,int>&mp, int &maxi){
        maxi = max(maxi ,i);
        
        if(node->left){
            helper(i+1, node->left, mp, maxi);
        }
        
        if(mp.find(i)== mp.end()){
            mp[i] = node->val;
        }
        
        if(node->right){
            helper(i+1, node->right, mp, maxi);
        }
        
    }
    
    int findBottomLeftValue(TreeNode* root) {
        unordered_map<int,int> mp;
        int maxi=0;
        helper(0,root,mp,maxi);
        return mp[maxi];
    }
};