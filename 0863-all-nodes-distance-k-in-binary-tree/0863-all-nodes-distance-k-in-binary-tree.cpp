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
    void mark_parent(TreeNode* node, unordered_map<TreeNode*,  TreeNode*>&mp){
        
        if(!node){
            return;
        }
        queue<TreeNode*> q;
        q.push(node);
        while(!q.empty()){
            
            TreeNode* temp= q.front();
            q.pop();
                
            if(temp->left){
                q.push(temp->left);
                mp[temp->left]= temp;
            }
            if(temp->right){
                q.push(temp->right);
                mp[temp->right]= temp;
            }
        }
        
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,  TreeNode*> parent;
        // store parent of nodes to we can traverse upwards too.
        
        mark_parent(root, parent);
        
        unordered_map<TreeNode*, bool> vis;
        // to store where we have visited the node earlier or not 
        // suppose we start we root, we move to root->left, 
        // when calc for root->left we dont want to take root again unnecessarily therefore we mark it visited and ignore vis
        
        // start from target and do bfs traversal till k, remaining nodes will be the at the distance of k;
        
        queue<TreeNode*> q;
        q.push(target);
        int dis=0;
        vis[target]=true;
        while(!q.empty()){
            int n= q.size();
            
            if(dis==k){
                break;
            }
            dis++;
            
            for(int i=0;i<n;i++){
                TreeNode* temp= q.front();
                q.pop();
                
                if(temp->left && !vis[temp->left]){
                    q.push(temp->left);
                    vis[temp->left]= true;
                }
                
                if(temp->right && !vis[temp->right]){
                    q.push(temp->right);
                    vis[temp->right]= true;
                }
                
                if(parent[temp] && !vis[parent[temp]]){
                    q.push(parent[temp]);
                    vis[parent[temp]]=  true;
                }
            }
        }
        
        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);    
            q.pop();
        }
        return ans;
    }
};