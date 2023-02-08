class Solution {
public:
    void dfs(int node, vector<int> adj[], vector<int>&vis){
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
        
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n+1,0);
        
        vector<int> adj[n+1];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]){
                    adj[i+1].push_back(j+1);
                    adj[j+1].push_back(i+1);
                }
            }
        }
        int prov=0;
        for(int i=1;i<=n;i++){
            if(!vis[i]){
                dfs(i,adj,vis);
                vis[i]=1;
                prov++;
            }
        }
        return prov;
    }
};