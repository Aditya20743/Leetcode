class Solution {
public:
    
    /*
    intution- 1. find shortest distance then count how many times we can reach 0 - n-1
    */
    long long mod= 1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<long long,long long>>> adj(n);
        
        for(int i=0;i<roads.size();i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        
        vector<long long> time(n,1e18);
        vector<long long> ways(n,0);
        
        priority_queue<pair<long long,long long>, vector<pair<long long,long long>>, greater<pair<long long,long long>> > pq;
        pq.push({0,0});
        ways[0]=1;
        time[0]=0;

        
        while(!pq.empty()){
            long long curr_time= pq.top().first;
            long long node= pq.top().second;
            pq.pop();
            
            for(auto it: adj[node]){
                long long nd= it.first;
                long long t= it.second;
                
                if(time[nd]> t+ curr_time){
                    time[nd]= t+ curr_time;
                    ways[nd]= ways[node];
                    pq.push({time[nd],nd});
                }
                
                else if( time[nd]== t + curr_time ){
                    // time[nd]= t+ curr_time;
                    ways[nd]= (ways[nd]+ ways[node])%mod;
                }
                
                
            }
        }
        return ways[n-1]%mod;

    }
};