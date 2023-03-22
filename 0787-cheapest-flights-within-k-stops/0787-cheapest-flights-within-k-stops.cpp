class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<int>> adj[n];
        for(int i=0;i<flights.size();i++){
            adj[flights[i][0]].push_back({flights[i][1],flights[i][2]});
        }
        vector<vector<int>> dis(n,vector<int>(k+2,INT_MAX));
        dis[src][0]= 0;
        
        queue<pair<int,int>> q;
        q.push({src,0});
        
        while(!q.empty()){
            int node= q.front().first;
            int steps= q.front().second;
            q.pop();
            
            for(auto it: adj[node]){
                int adjn= it[0];
                int adjW= it[1];
                
                if(steps<k+1 &&  dis[adjn][steps+1] > dis[node][steps]+ adjW){
                    dis[adjn][steps+1]= dis[node][steps]+ adjW;
                    q.push({adjn,steps+1});
                }
            }
        }
        int ans= INT_MAX;
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<k+2;j++){
        //         cout<<dis[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        for(int i=0;i<=k+1;i++){
            if(dis[dst][i] != INT_MAX){
                ans= min(ans,dis[dst][i]);
            }
        }
        return ans== INT_MAX ? -1 : ans; 
    }
};