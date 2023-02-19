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
         if(root==NULL)  return ans;
         queue<TreeNode*>q;
         bool lefttoRight=true;
         q.push(root);
         while(!q.empty()){
             int size=q.size();
             vector<int> row(size);
             for(int i=0;i<size;i++){
                 TreeNode* curr=q.front();
                 q.pop();
                 
                 int index=i;
                 row[index]=curr->val;
                 if(curr->left){
                     q.push(curr->left);
                 }
                 if(curr->right){
                     q.push(curr->right);
                 }
                 
             }
             lefttoRight=!lefttoRight;
             if(lefttoRight)   reverse(row.begin(),row.end());
             ans.push_back(row);
         }
        return ans;
         
        
    }
};