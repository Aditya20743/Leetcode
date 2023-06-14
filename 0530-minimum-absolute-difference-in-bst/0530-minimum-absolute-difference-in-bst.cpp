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
    void traverse(TreeNode* node, vector<int>& v){
        if(node==NULL){
            return;
        }
        v.push_back(node->val );
        traverse(node->left, v);
        traverse(node->right,v);
    }
    
    int getMinimumDifference(TreeNode* root) {
        vector<int> v;
        traverse(root, v);

        sort(v.begin(),v.end());
        int ans=INT_MAX;
        for(int i=1;i<v.size();i++){
            ans= min(ans, v[i]-v[i-1]);
        }
        return ans;
    }
};