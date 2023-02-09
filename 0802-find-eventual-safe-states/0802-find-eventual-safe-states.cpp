class Solution {
public:
    bool dfs(int node,vector<int>&vis, vector<vector<int>>& graph,
            vector<int>& path,vector<int>& check){
        vis[node]=1;
        path[node]=1;
        
        
        for(auto it: graph[node]){
            if(!vis[it]){
                if(dfs(it,vis,graph,path,check)==true)
                    return true;   //cycle present
            }
            else if(path[it]==1){
                return true;  // cycle present
            }
        }
        path[node]=0;
        check[node]=1;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n= graph.size();
        vector<int> vis(n,0);
        vector<int> path(n,0);
        vector<int> check(n,0);
        
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,graph,path,check);
                vis[i]=1;
            }
        }
        
        
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(check[i]==1)   ans.push_back(i);
        }
        return ans;
    }
};