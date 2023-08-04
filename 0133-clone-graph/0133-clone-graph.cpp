/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
Node* dfs(Node* curr, unordered_map<Node*,Node*>& mp){
    vector<Node*> adjList;
    Node* clone = new Node (curr->val);
    mp[curr] = clone;
    
    for(auto it: curr->neighbors){
        // if already cloned just push cloned version stored in mp
        if(mp.find(it)!= mp.end()){  
            adjList.push_back(mp[it]);
        }
        else{
            // if not do dfs and get cloned version , in dfs it will be mapped
            adjList.push_back(dfs(it, mp));
        }
    }
    clone->neighbors= adjList;
    return clone;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return NULL;
        }
        if(node->neighbors.size()==0){
            Node* clone= new Node(node->val);
            return clone;
        }
        
        unordered_map<Node*, Node*> mp;
        return dfs(node, mp);
    }
};