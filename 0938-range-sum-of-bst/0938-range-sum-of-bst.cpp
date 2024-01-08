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
    int rangeSumBST(TreeNode* t, int l, int h) {
        int sum=0;
        if(t->val >=l && t->val<= h)    sum+= t->val;
        
        if(t->val > h){
            if(t->left){
                sum+= rangeSumBST(t->left, l,h);
            }
        }
        else if(t->val < l){
            if(t->right){
                sum+= rangeSumBST(t->right, l,h);
            }
        }
        else{
            if(t->left){
                sum+= rangeSumBST(t->left, l,h);
            }
            if(t->right){
                sum+= rangeSumBST(t->right, l,h);
            }
        }
        
        return sum;
    }
};