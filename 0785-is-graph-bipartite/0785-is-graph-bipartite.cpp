class Solution {
public:
    bool dfs(int i, int c, vector<vector<int>>& graph, vector<int>&col, vector<int>&vis){
        vis[i]=1;
        col[i]=c;
        
        for(auto it: graph[i]){
            if(vis[it]==1 && col[it]== c){
                return false;
            }
            else if(vis[it]==0 ){
                // cout<<c<<endl;
                if(dfs(it, !c, graph, col, vis)==false){
                    return false;
                }
            }
        }
        return true;
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> col(n,0), vis(n,0);
        
        // start col with 1;
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                 if(dfs(i,1,graph,col,vis)==false){
                     return false;
                 }
            }
        }
        return true;
    }
};