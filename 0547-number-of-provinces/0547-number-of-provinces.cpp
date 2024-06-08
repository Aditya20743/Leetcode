class Solution {
public:
    void dfs(int i, vector<vector<int>>&adj, vector<int>&vis){
        vis[i]=1;
        
        for(auto it: adj[i]){
            if(vis[it]==0){
                dfs(it, adj, vis);
            }
        }
    }
    
    void bfs(int i, vector<vector<int>>&adj, vector<int>&vis){
        vis[i]=1;
        queue<int> q;
        q.push(i);
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            for(auto it: adj[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        
    }
    
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n= isConnected.size();
        vector<int> vis(n,0);
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        int ans=0;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                bfs(i, adj, vis);
                ans++;
            }
        }
        
        return ans;
    }
};