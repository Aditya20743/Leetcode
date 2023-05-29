class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        
        for(int i=0;i<flights.size();i++){
            int a= flights[i][0];
            int b= flights[i][1];
            int p= flights[i][2];
            
            adj[a].push_back({b,p});
        }
        
        
        vector<vector<int>> prices(n,vector<int>(n+2,INT_MAX));
        prices[src][0]=0;
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        pq.push({0,src});
        
        while(!pq.empty()){
            int node = pq.top().second;
            int trips= pq.top().first;
            pq.pop();
            
            // if(trips == k+3)  break;
            for(auto it: adj[node]){
                int adjNode=  it.first;
                int EdgeW= it.second;
                
                
                if(trips<k+1 && prices[adjNode][trips+1] > prices[node][trips] + EdgeW){
                    prices[adjNode][trips+1] = prices[node][trips] + EdgeW;
                    pq.push({trips+1, adjNode});
                }
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<=min(k+1,n);j++){
            mini= min(mini, prices[dst][j]);
        }
            
        return mini==INT_MAX ? -1: mini;
    }
};