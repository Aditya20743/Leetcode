//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<pair<int,int>> adj[n];
        for(auto it: roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        int mod= 1e9+7;
        priority_queue< pair<int,int>, vector<pair<int,int>>,
        greater<pair<int,int>> > minh;
        
        vector<int> dis(n,1e9);
        vector<int> ways(n,0);
        ways[0]=1;
        dis[0]=0;
        
        minh.push({0,0});
        
        while(!minh.empty()){
            int node= minh.top().second;
            int dist= minh.top().first;
            minh.pop();
            
            for(auto it: adj[node]){
                int edis= it.second;
                int enode= it.first;
                if(dist+ edis < dis[enode] ){
                    dis[enode]= dist+ edis;
                    minh.push({dis[enode],enode});
                    ways[enode]=ways[node];
                }
                else if(dist+ edis == dis[enode]){
                    ways[enode]+= ways[node]% mod;
                }
            }
        }
        return ways[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    while (T--) {
        int n, m;
        cin >> n >> m;
        int u, v;

        vector<vector<int>> adj;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            adj.push_back(temp);
        }

        Solution obj;
        cout << obj.countPaths(n, adj) << "\n";
    }

    return 0;
}
// } Driver Code Ends