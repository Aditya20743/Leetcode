class Disjoint{
    public:
    vector<int> rank, size, parent;
    
    Disjoint(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] =1;
        }
    }
    
    int FindUparent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = FindUparent(parent[node]);
    }
    
    void UnionByRank(int u, int v){
        int ulp_u = FindUparent(u);
        int ulp_v = FindUparent(v);
        
        if(ulp_u == ulp_v){
            // already connected
            return;
        }
        
        if(rank[ulp_u]> rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u]< rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
    void UnionBySize(int u,int v){
        int ulp_u = FindUparent(u);
        int ulp_v = FindUparent(v);
        
        if(ulp_u == ulp_v){
            // already connected
            return;
        }
        
        if(size[ulp_u]> size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_v]+= size[ulp_u];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_u]+= size[ulp_v];
        }
    }
    
};

class Solution {
public:
    // void dfs(int node,vector<int>&vis, vector<int> adj[]  ){
    //     vis[node]=1;
    //     for(auto it: adj[node]){
    //         if(!vis[it]){
    //             dfs(it,vis,adj);
    //         }
    //     }
    // }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int size= connections.size();
        if(size< n-1)   return -1;
        
        Disjoint dsu(n);
        
        int extraEdges=0;
        for(auto it: connections){
            
            if(dsu.FindUparent(it[0]) == dsu.FindUparent(it[1])){
                extraEdges++;
            }
            else{
                dsu.UnionBySize(it[0], it[1]);
            }
        }
        
        int countcomp= 0;
        
        for(int i=0;i<n;i++){
            if(dsu.parent[i] == i){
                // only boss will have parent[i] = i;
                countcomp++;
            }
        }
        
        if(extraEdges >= countcomp-1)   return countcomp-1;
        return -1;
        
        
        
//         vector<int> adj[n];
//         for(int i=0;i<size;i++){
//             adj[connections[i][0]].push_back(connections[i][1]);
//             adj[connections[i][1]].push_back(connections[i][0]);
//         }
        
        // vector<int> vis(n,0);
        // int count=0;
        // for(int i=0;i<n;i++){
        //     if(!vis[i]){
        //         dfs(i,vis,adj);
        //         vis[i]=1;
        //         count++;
        //     }
        // }
        // return count-1;
    }
};