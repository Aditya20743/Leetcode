class Solution {
public:
    bool bfs(int node, vector<int>&col, vector<int>&vis, vector<vector<int>>&graph){
        col[node]=1;
        queue<pair<int,int>> q;
        q.push({1,node});
        
        while(!q.empty()){
            int color= q.front().first;
            int nd= q.front().second;
            q.pop();
            
            for(auto it: graph[nd]){
                if(col[it]== color){
                    return false;
                }
                else if(vis[it]== 0){
                    col[it]= -color;
                    vis[it]=1;
                    q.push({col[it], it});
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> col(n,0);
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(bfs(i,col,vis, graph)==false){
                    return false;
                }
            }
        }
        return true;
    }
};