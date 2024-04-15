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
    void sumN(TreeNode* t,int &cur,int &sum){
        if(!t)  return ;
        
        cur= cur*10+ t->val;
        if(!t->left && !t->right) {sum+= cur; return;}
        
        sumN(t->left,cur,sum);
        if(t->left)
            //cout<<cur<<"-curr ";
            cur= cur/10;
        sumN(t->right,cur,sum);
        if(t->right)
            cur=cur/10;
        //cur= cur/10;
        
    }
    int sumNumbers(TreeNode* root) {
        vector<int> v;
        int cur=0,sum=0;
        sumN(root,cur,sum);
        
        return sum;
    }
};