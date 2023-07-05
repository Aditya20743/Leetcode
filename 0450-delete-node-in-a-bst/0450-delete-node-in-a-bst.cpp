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
    TreeNode* helper(TreeNode* node){
        if(!node->left){
            return node->right;
        }
        else if(!node->right){
            return node->left;
        }
        TreeNode* right_child= node->right;
        TreeNode* last_right= findLastRight(node->left);
        
        last_right->right= right_child;
        
        return node->left;
    }
    TreeNode* findLastRight(TreeNode* temp){
        if(temp->right==NULL){
            return temp;
        }
        return findLastRight(temp->right);
    }
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)   return root;
        if(root->val== key)     return helper(root);
        
        TreeNode* temp= root;
        
        while(temp){
            if(temp->val > key){
                if(temp->left && temp->left->val ==key){     
                    temp->left= helper(temp->left);
                    break;
                }
                else
                    temp=temp->left;
            }
            else{
                if(temp->right && temp->right->val ==key){     
                    temp->right= helper(temp->right);
                    break;
                }
                else
                    temp=temp->right;
            }
        }
        
        return root;
    }
};
    
//     void helper(TreeNode* root, int key){
//         if(!root)   return ;
        
//         if((root->left && root->left->val ==key) || (root->right && root->right->val ==key)){
//             if(root->left && root->left->val ==key){
//                 if(!root->right){
//                     root->left= NULL;
//                     return ;
//                 }
//                 else{
//                     root->left= root->right;
//                     root->right=NULL;
//                     return ;
//                 }
//             }
//             if(root->right && root->right->val ==key){
//                 if(!root->left){
//                     root->right= NULL;
//                     return ;
//                 }
//                 else{
//                     root->right= root->left;
//                     root->left=NULL;
//                     return ;
//                 }
//             }
//         }
        
//         if(root->val >key ){
//             helper(root->left,key);
//         }
//         else
//             helper(root->right,key);
//     }
    