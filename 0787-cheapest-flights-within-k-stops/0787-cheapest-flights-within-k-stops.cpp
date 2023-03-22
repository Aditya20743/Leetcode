class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<int> dis(n,INT_MAX);
        dis[src]= 0;
        
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});
        
        while(!q.empty()){
            int node= q.front().second.first;
            int steps= q.front().first;
            int distance= q.front().second.second;
            q.pop();
            
            for(auto it: adj[node]){
                int adjn= it[0];
                int adjW= it[1];
                
                if(steps<k+1 &&  dis[adjn] > distance+ adjW){
                    dis[adjn]= distance + adjW;
                    q.push({steps+1,{adjn,dis[adjn]}});
                }
            }
        }
        //int ans= INT_MAX;
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<k+2;j++){
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        // for(int i=0;i<=k+1;i++){
        //     if(dis[dst][i] != INT_MAX){
        //         ans= min(ans,dis[dst][i]);
        //     }
        // }
        return dis[dst] == INT_MAX ? -1 : dis[dst]; 
    }
};