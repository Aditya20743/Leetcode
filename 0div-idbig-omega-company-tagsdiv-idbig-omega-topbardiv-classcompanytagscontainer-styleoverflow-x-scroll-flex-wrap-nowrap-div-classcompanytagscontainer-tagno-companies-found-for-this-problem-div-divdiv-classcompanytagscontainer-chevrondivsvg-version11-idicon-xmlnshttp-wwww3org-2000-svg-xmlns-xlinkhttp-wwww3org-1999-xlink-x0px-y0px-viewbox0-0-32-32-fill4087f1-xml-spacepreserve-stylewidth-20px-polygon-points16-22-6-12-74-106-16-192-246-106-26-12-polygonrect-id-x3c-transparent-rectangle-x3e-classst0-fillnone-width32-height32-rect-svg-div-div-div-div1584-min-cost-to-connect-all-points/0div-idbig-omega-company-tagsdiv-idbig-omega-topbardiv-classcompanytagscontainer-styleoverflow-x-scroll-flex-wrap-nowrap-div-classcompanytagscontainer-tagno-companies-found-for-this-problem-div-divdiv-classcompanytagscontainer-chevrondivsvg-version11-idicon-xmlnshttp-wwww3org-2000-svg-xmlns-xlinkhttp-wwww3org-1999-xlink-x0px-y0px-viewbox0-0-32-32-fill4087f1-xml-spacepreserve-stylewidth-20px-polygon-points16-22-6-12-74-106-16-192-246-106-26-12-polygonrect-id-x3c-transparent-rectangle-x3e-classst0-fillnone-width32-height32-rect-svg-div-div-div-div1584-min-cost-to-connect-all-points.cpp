class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n= points.size();
        
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int dis = abs(points[i][0]-points[j][0]) + abs(points[i][1]- points[j][1]);
                
                adj[i].push_back({j,dis});
                adj[j].push_back({i,dis});
            }
        }
        
        
        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq;
        pq.push({0,0});
        int sum=0;
        vector<bool> vis(n,false);
        
        while(!pq.empty()){
            int wt= pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            if(vis[node]==true)     continue;
            
            sum+= wt;
            vis[node] = true;
            
            for(auto it: adj[node]){
                
                int adjwt = it.second;
                int adjnode = it.first;
                
                if(!vis[adjnode]){
                    pq.push({adjwt,adjnode});
                }
                
            }
        }
        return sum;
    }
};