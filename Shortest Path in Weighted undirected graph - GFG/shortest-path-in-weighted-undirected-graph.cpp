//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        // Code here
        vector<pair<int,int>> adj[n+1];
        
            for(auto it: edges){
                adj[it[0]].push_back({it[1],it[2]});
                adj[it[1]].push_back({it[0],it[2]});
            }
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>> > minh;
        minh.push({0,1});
        
        vector<int> dis(n+1,INT_MAX);
        dis[1]=0;
        vector<int> parent(n+1);
        for(int i=1;i<n+1;i++)  parent[i]=i;
        
        while(!minh.empty()){
            int dist= minh.top().first;
            int node= minh.top().second;
            minh.pop();
            
            for(auto it: adj[node]){
                int edgeW= it.second;
                int edgeN= it.first;
                if(edgeW+ dist < dis[edgeN]){
                    dis[edgeN]= edgeW+ dist;
                    parent[edgeN]= node;
                    minh.push({dis[edgeN],edgeN});
                }
            }
        }
        vector<int> path;
        if(dis[n]== INT_MAX)    
            return {-1};
        else{
            
        while(parent[n]!=n){
            path.push_back(n);
            n= parent[n];
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
            
        }
        
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