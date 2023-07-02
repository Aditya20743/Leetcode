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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root)   return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left_to_right = true;
        
        while(!q.empty()){
            int n=q.size();
            int lvl;
            vector<int> row;
            for(int i=0;i<n;i++){
                
                TreeNode* node= q.front();
                q.pop();
                row.push_back(node->val);
                
                if(node->left)
                    q.push(node->left);
                if(node->right){
                    q.push(node->right);
                }
            }
            if(!left_to_right){
                reverse(row.begin(),row.end());
            }
            left_to_right=!left_to_right;
            ans.push_back(row);
            row.clear();
            
        }
        return ans;
    }
};