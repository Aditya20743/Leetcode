//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>, vector<pair<int,int>>, 
        greater<pair<int,int>> > min_heap;
        
        vector<int> shortest_distance(V, INT_MAX);
        
        min_heap.push({0,S});
        shortest_distance[S]=0;
        
        while(!min_heap.empty()){
            int dis= min_heap.top().first;
            int node= min_heap.top().second;
            min_heap.pop();
            
            for(auto it: adj[node]){
                int adjnode= it[0];
                int adjdis= it[1];
                
                if(shortest_distance[adjnode] > adjdis + dis){
                    shortest_distance[adjnode]= adjdis + dis;
                    min_heap.push({shortest_distance[adjnode],adjnode});
                }
            }
        }
        for(int i=0;i<V;i++){
            if(shortest_distance[i]==INT_MAX){
                shortest_distance[i]=-1;
            }
        }
        return shortest_distance;
    }
};


//{ Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}


// } Driver Code Ends