class Solution {
public:
    void dfs(int node, vector<int>&vis, vector<int> adj[],long long & no){
        vis[node]=1;
        no++;
        for(auto it: adj[node]){
            if(!vis[it]){
                dfs(it,vis,adj,no);
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        long long nodes=n;
        if(edges.size()==0) return nodes*(nodes-1)/2;
        vector<int> adj[n];
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        
        long long no=0;
        long long comp=0,ans=0;
        
        vector<long long> v;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                no=0;
                dfs(i,vis,adj,no);
                
                v.push_back(no);
                no=1;
                comp++;
                
            }
        }
        for(int i=0;i<v.size();i++){
            for(int j=i+1;j<v.size();j++){
                ans+= v[i]*v[j];
            }
        }
        if(comp==1) return 0;
        
        return ans;
    }
};