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
// class Solution {
// public:
//     void helper(TreeNode* root, vector<int>& v){
//         if(!root)   return;
//         v.push_back(root->val);
//         helper(root->left,v);
//         helper(root->right,v);
//     }
//     vector<int> preorderTraversal(TreeNode* root) {
//         vector<int> v;
//         helper(root, v);
//         return v;
//     }
// };
class Solution {
public:
    // stack-> preorder -> first ans.push st.front()->val,  
    // then st.push(st.front()->right);
    // st.push(st.front()->left);
    // st.pop()
    // first push right then left so that left is taken before right.
    
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        
        if(root== NULL) return ans;
        
        stack<TreeNode* > st;
        
        st.push(root);
        
        while(!st.empty()){
            TreeNode* temp= st.top();
            st.pop();
            ans.push_back(temp->val);
            
            if(temp->right!= NULL){
                st.push(temp->right);
            }
            if(temp->left!= NULL){
                st.push(temp->left);
            }
        }
        return ans;
    }
};