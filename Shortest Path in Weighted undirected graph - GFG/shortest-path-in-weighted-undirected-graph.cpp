//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        vector<int> dis(n+1,INT_MAX), parent(n+1,INT_MAX);
        for(int i=1;i<=n;i++){
            parent[i]=i;
        }
        
        for(int i=0;i<m;i++){
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0],edges[i][2]});
        }
        
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        dis[1]=0;
        
        pq.push({0,1});
        
        while(!pq.empty()){
            int node= pq.top().second;
            int distance= pq.top().first;
            pq.pop();
            
            for(auto it: adj[node]){
                int adjn= it.first;
                int adjw= it.second;
                
                if(dis[adjn]> adjw + distance){
                    dis[adjn]= adjw + distance;
                    pq.push({dis[adjn],adjn});
                    parent[adjn]= node;
                }
            }
        }
        if(dis[n]== INT_MAX)    return {-1};
        int node=n;
        vector<int> path;
        while(parent[node]!= node){
            path.push_back(node);
            node= parent[node];
        }
        path.push_back(node);
        reverse(path.begin(),path.end());
        return path;
        
    }
};

//{ Driver Code Starts.
int main() {
    // your code goes here
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        Solution obj;
        vector<int> res = obj.shortestPath(n, m, edges);
        for (auto x : res) {
            cout << x << " ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends