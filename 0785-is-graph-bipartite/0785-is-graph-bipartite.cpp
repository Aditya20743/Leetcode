class Solution {
public:
    bool bfs(int node, int col, vector<vector<int>>& graph, vector<int>&vis,vector<int>&color){
        color[node]= col;
        vis[node]=1;
        queue<pair<int,int>> q;
        q.push({node,col});
        
        while(!q.empty()){
            int nd = q.front().first;
            int c= q.front().second;
            vis[nd]= 1;
            color[nd]= c;
            q.pop();
            
            for(auto it: graph[nd]){
                if(!vis[it] ){
                    
                    vis[it]=1;
                    color[it]= -c;
                    q.push({it,-c}); 
                   
                }
                else if(vis[it] && color[it]== c){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        
        int n= graph.size();
        
        vector<int> vis(n,0);
        vector<int> color(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                if(bfs(i,1,graph,vis,color)==false){
                    return false;
                }
            }
        }
        return true;
    }
};