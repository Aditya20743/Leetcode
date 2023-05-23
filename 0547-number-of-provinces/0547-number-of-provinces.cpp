class Solution {
public:
    void bfs(int node, vector<vector<int>>adj ,vector<int>& vis){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        while(!q.empty()){
            int next= q.front();
            q.pop();
            for(auto it: adj[next]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(n,0);
        
        int c=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i, adj, vis);
                c++;
            }
        }
        return c;
    }
};