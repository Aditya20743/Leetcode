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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        vector<int> v;
        q.push({root});
        while(!q.empty()){
            int s= q.size();
            for(int i=0;i<s;i++){
                TreeNode* t= q.front();
                q.pop();
                if(t){   
                    v.push_back(t->val);
                    if(t->left) q.push(t->left);
                    if(t->right) q.push(t->right);
                }
            }
            if(v.size()){
                ans.push_back(v);
                v.clear();
            }
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};