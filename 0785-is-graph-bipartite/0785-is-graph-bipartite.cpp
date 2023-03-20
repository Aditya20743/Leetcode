class Solution {
public:
    bool bfs(int node,vector<vector<int>>& graph, vector<int>& vis,vector<int>& col){
        queue<pair<int,int>> q;
        q.push({node, -1});
        vis[node]=1;
        col[node]=-1;
        
        while(!q.empty()){
                int node= q.front().first;
                int color= q.front().second;
                q.pop();

                for(auto it: graph[node]){
                    if(!vis[it] ){
                        col[it]=(-color);
                        vis[it]=1;
                        q.push({it,col[it]});
                    }
                    else if(vis[it]==1 && col[it]== color){
                        return false;
                    }
                }
            }
        return true;
    }
    bool dfs(int node,vector<vector<int>>& graph, vector<int>& vis,vector<int>& col,int color){
        vis[node]=1;
        col[node]=color;
        
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it,graph,vis,col,!color)==false) return false;
            }
            else if(vis[it]==1 && col[it]== color){
                return false;
            }
        }
        return true;
    }
    
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,0);  // (1, -1)
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(dfs(i,graph,vis,col,1)==false)     return false;
            }
        }
        return true;
        
    }
};