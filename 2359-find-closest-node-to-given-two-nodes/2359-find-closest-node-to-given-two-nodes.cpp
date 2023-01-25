class Solution {
public:
    void dfs(vector<int>& edges, int node, vector<int>&vis, vector<int>&dis){
        vis[node]=1;
        int v = edges[node];
        
        if(v!= -1 && vis[v]==-1){
            dis[v]=dis[node]+1;
            dfs(edges,v,vis,dis);
        }
    }
    int n;
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        n= edges.size();
        
        vector<int> vis1(n,-1);
        vector<int> vis2(n,-1);
        
        vector<int> dis1(n,INT_MAX);
        vector<int> dis2(n,INT_MAX);
        
        dis1[node1]=0;
        dis2[node2]=0;
        
        dfs(edges,node1,vis1,dis1);
        dfs(edges,node2,vis2,dis2);
        
        int mininode=-1;
        int dis= INT_MAX;
        
        for(int i=0;i<n;i++){
            if(dis> max(dis1[i],dis2[i])){
                dis = max(dis1[i],dis2[i]);
                mininode= i;                
            }
        }
        return  mininode; 
    }
};