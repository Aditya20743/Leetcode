class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<int>> adj[n+1];
        for(int i=0;i<times.size();i++){
            adj[times[i][0]].push_back({times[i][1],times[i][2]});
        }
        
        priority_queue< pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>> > pq;
        
        pq.push({0,k});
        // prev time, timereq, node
        vector<int> time(n+1,INT_MAX);
        time[k]=0;
        
        //int t_max= 0;
        while(!pq.empty()){
            int curr_time= pq.top().first;
            //int req_time= pq.front().second.first;
            int node= pq.top().second;
            
            pq.pop();
            //t_max=max(t_max, curr_time);
            
            for(auto it: adj[node]){
                int req_time= it[1];
                int adjN= it[0];
                
                if(time[adjN]> req_time + curr_time){
                    time[adjN]= req_time + curr_time;
                    pq.push({time[adjN], adjN});
                }
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX)    return -1;
            //cout<<"i- "<<time[i]<<" ";
            ans=max(ans,time[i]);
        }
        //cout<<endl;
        return ans;
    }
};