class Solution {
public:
    #define ll long long 
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<ll >>adj[n];
        long long mod=1e9+7;
        vector<int> ways(n,0);
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1],roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0],roads[i][2]});
        }
        
        priority_queue<pair<ll,ll>, vector<pair<ll,ll>> , greater<pair<ll,ll>> > pq;
        pq.push({0,0});
        ways[0]=1;
        
        vector<ll> time(n,1e18);
       
        
        while(!pq.empty()){
            ll currtime= pq.top().first;
            ll node= pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                ll newtime= it[1];
                ll adjn= it[0];
                
                
                if(time[adjn]> currtime+newtime){
                    time[adjn]= currtime+ newtime;
                    pq.push({time[adjn],adjn});
                    ways[adjn]= ways[node]%mod;
                }
                else if(time[adjn] == currtime+ newtime){
                    ways[adjn]=(ways[adjn]+ ways[node])%mod;
                }
                // if(adjn==n-1 ){
                //     if(time[adjn]< mintime){
                //         count=1;
                //         mintime= min(time[adjn],mintime);
                //     }
                //     else if(time[adjn]== mintime){
                //         count++;
                //     }
                // }
            }
        }
        return ways[n-1]%mod;
    }
};