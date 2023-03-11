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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if(nums.size()==0)  return NULL;
        
        if(nums.size()==1)    return new TreeNode (nums[0]);
        
        int n=nums.size()/2;
        TreeNode* root= new TreeNode(nums[n]);
        vector<int> t1,t2;
        for(int i=0;i<n;i++)   {t1.push_back(nums[i]); cout<<nums[i]<<" ";}
        for(int j=n+1;j<nums.size();j++)   { t2.push_back(nums[j]); cout<<nums[j]<<" ";}
        
        root->left= sortedArrayToBST(t1);
        root->right= sortedArrayToBST(t2);
        return root;
    }
};
// class Solution {
// public:
//     TreeNode *sortedArrayToBST(vector<int> &num) {
//         if(num.size() == 0) return NULL;
//         if(num.size() == 1)
//         {
//             return new TreeNode(num[0]);
//         }
        
//         int middle = num.size()/2;
//         TreeNode* root = new TreeNode(num[middle]);
        
//         vector<int> leftInts(num.begin(), num.begin()+middle);
//         vector<int> rightInts(num.begin()+middle+1, num.end());
        
//         root->left = sortedArrayToBST(leftInts);
//         root->right = sortedArrayToBST(rightInts);
        
//         return root;
//     }
// };