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
    void insert(TreeNode* root,int val,int d,int cd){
        if(root==NULL)  return;
        if(cd==d){
            TreeNode* temp= root->left;
            //root->left= new TreeNode(val);
            root->left = new TreeNode(val);
            root->left->left=temp;

            temp=root->right;
            root->right = new TreeNode(val);
            root->right->right=temp;
            return;
        }
        else{
            insert(root->left,val,d,cd+1);
            insert(root->right,val,d,cd+1);
        }

    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth==1){
            TreeNode* t;
            t= new TreeNode(val);
            t->left=root;
            return t;
        }
        insert(root,val,depth,2);
        return root;
    }
};
// class Solution {
// public:
//     void addOneRowR(TreeNode* root, int v, int d, int cd) {
//         if (!root) return;
        
//         if (cd == d) {
//             TreeNode *savLeft = root->left;
//             root->left = new TreeNode(v);
//             root->left->left = savLeft;
            
//             TreeNode *savRight = root->right;
//             root->right = new TreeNode(v);
//             root->right->right = savRight;
//             return;
//         }
//         addOneRowR(root->left, v, d, cd + 1);
//         addOneRowR(root->right, v, d, cd + 1);
//     }
//     TreeNode* addOneRow(TreeNode* root, int v, int d) {
//         if (d == 1) {
//             TreeNode *newRoot = new TreeNode(v);
//             newRoot->left = root;
//             return newRoot;
//         }
//         addOneRowR(root, v, d, 2);
//         return root;
//     }
// };