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
    int countNodes(TreeNode* root) {
        int count=0;
        if(!root)   return count;
        
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            int n=q.size();
            
            for(int i=0;i<n;i++){
                TreeNode* temp= q.front();
                q.pop();
                
                if(temp->left){
                    q.push(temp->left);
                    count++;
                }
                if(temp->right){
                    q.push(temp->right);
                    count++;
                }
            }
            
        }
        
        return count+1;
    }
};