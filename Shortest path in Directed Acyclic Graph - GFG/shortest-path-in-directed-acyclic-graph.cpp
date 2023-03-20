//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
class Solution {
private:
    void topo(vector<pair<int,int>>adj[], stack<int>&s,vector<int>&vis,int node){
        //int n= adj.size();
        vis[node]=1;
        
        for(auto it: adj[node]){
            if(!vis[it.first]){
                topo(adj,s,vis,it.first);
            }
        }
        s.push(node);
        // vector<int> indeg(n,0);
        // for(int i=0;i<n;i++){
        //     for(auto it: adj[i]){
        //         indeg[it[0]]++;
        //     }
        // }
        
    }
  public:
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        // code here
        vector<pair<int,int>> adj[N];
        for(int i=0;i<M;i++){
            int en1= edges[i][0];
            int en2= edges[i][1];
            int ew= edges[i][2];
            adj[en1].push_back({en2,ew});
        }
        stack<int> s;
        vector<int> vis(N,0);
        for(int i=0;i<N;i++){
            if(!vis[i]){
                topo(adj,s,vis,i);
            }
        }
        int src=0;
        
        vector<int> dis(N,1e9);
        dis[src]=0;
        while(s.top()!= src){
            s.pop();
        }
        while(!s.empty()){
            int node=s.top();
            s.pop();
            for(auto it: adj[node]){
                int newnode= it.first;
                int d= it.second;
                
                if(dis[newnode]> d+ dis[node]){
                    dis[newnode]= d+ dis[node];
                }
            }
        }
        for(int i=0;i<N;i++){
            if(dis[i]==1e9){
                dis[i]=-1;
            }
        }
        return dis;
        
        
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> edges;
        for(int i=0; i<m; ++i){
            vector<int> temp;
            for(int j=0; j<3; ++j){
                int x; cin>>x;
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