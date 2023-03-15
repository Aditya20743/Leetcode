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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        vector<vector<int>> ans;
        vector<int> v;
        int plvl= 0;
        while(!q.empty()){
            int lvl= q.front().first;
            TreeNode* node= q.front().second;
            q.pop();
            
            if(lvl> plvl){
                if(node){
                ans.push_back(v);
                plvl= lvl;
                v.clear();
                v.push_back(node->val);
                if(node->left)
                q.push({lvl+1,node->left});
                if(node->right)
                q.push({lvl+1,node->right});}
                
            }
            else{
                if(node){
                v.push_back(node->val);
                if(node->left)
                q.push({lvl+1,node->left});
                if(node->right)
                q.push({lvl+1,node->right});}
            }
        }
        if(v.size()){
            ans.push_back(v);
        }
        return ans;
    }
};