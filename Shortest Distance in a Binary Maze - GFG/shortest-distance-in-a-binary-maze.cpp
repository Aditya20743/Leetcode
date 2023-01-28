//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
    
  public:
  
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination) {
        // code here
        if(source== destination)    return 0;
        queue< pair<int,pair<int,int>> > q;
        q.push({0,source});
        
        int n=grid.size();  
        int m=grid[0].size();
        
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        dis[source.first][source.second]= 0;
        
        int dir[5]={-1,0,1,0,-1};
        
        while(!q.empty()){
            int nodex= q.front().second.first;
            int nodey= q.front().second.second;
            int dist= q.front().first;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nx= nodex+ dir[i];
                int ny= nodey+ dir[i+1];
                if(nx>=0 && nx<n && ny>=0 && ny<m && grid[nx][ny]==1){
                    if(nx== destination.first && ny== destination.second)
                        return dist+1;
                    if(dist+ 1 < dis[nx][ny]){
                        dis[nx][ny]= 1+ dist;
                        q.push({dis[nx][ny],{nx,ny}});
                    }
                }
            }
        }
        return  -1;
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int>> grid(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }

        pair<int, int> source, destination;
        cin >> source.first >> source.second;
        cin >> destination.first >> destination.second;
        Solution obj;
        cout << obj.shortestPath(grid, source, destination) << endl;
    }
}

// } Driver Code Ends