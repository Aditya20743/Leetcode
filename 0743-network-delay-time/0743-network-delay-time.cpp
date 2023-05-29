class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue< pair<int,int> , vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        vector<vector<pair<int,int>>> adj(n+1);
        
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        
        vector<int> t(n+1,INT_MAX);
        t[k]=0;
        
        pq.push({0,k});
        
        while(!pq.empty()){
            int node= pq.top().second;
            int time= pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                if(t[it.first] > time + it.second){
                    t[it.first]= time+ it.second;
                    
                    pq.push({t[it.first], it.first});
                }
            }
        }
        int maxi=INT_MIN;
        
        for(int i=1;i<n+1;i++){
            maxi= max(t[i], maxi);
        }
        return maxi== INT_MAX ? -1 : maxi;
        
    }
};