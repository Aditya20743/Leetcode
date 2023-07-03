/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool path_finder(TreeNode* node, TreeNode* p, vector<TreeNode*>&temp){
        if(!node){
            return false;
        }
        
        if(node==p){
            temp.push_back(p);
            return true;
        }
        
        temp.push_back(node);
        if(path_finder(node->left, p, temp) || path_finder(node->right,p, temp)){
            return true;
        }
        temp.pop_back();
        return false;
    }
    
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(p==q)    return p;
        
        vector<TreeNode*> path1;
        path_finder(root, p, path1);
        
        vector<TreeNode*> path2;
        path_finder(root, q, path2);
        
        cout<<path1.size()<<" "<<path2.size()<<endl;
        
        for(int i=0;i<min(path1.size(),path2.size());i++){
            if(path1[i]!= path2[i]){
                return path1[i-1];
            }
        }
        return path1[min(path1.size(), path2.size())-1];
    }
};