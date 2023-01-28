//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int MinimumEffort(vector<vector<int>>& heights) {
        // Code here
        priority_queue< pair<int,pair<int,int>> , 
        vector<pair<int,pair<int,int>>>,
        greater<pair<int,pair<int,int>>> > minh;
        
        int n= heights.size();
        int m= heights[0].size();
        
        // vector<vector<pair<int,int>>> parent(n,m);
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++)    parent[i][j]={i,j};
        // }
        vector<vector<int>> eff(n,vector<int>(m,INT_MAX));
        minh.push({0,{0,0}});
        int dir[5]={-1,0,1,0,-1};
        while(!minh.empty()){
            int effort= minh.top().first;
            int hx= minh.top().second.first;
            int hy= minh.top().second.second;
            
            minh.pop();
            for(int i=0;i<4;i++){
                int nhx= hx+ dir[i];
                int nhy= hy+ dir[i+1];
                if(nhx>=0 && nhy>=0 && nhx<n && nhy<m){
                    
            int newEff= max(abs(heights[nhx][nhy]-heights[hx][hy]),effort);
                    if(newEff< eff[nhx][nhy]){
                        eff[nhx][nhy]= newEff;
                        minh.push({newEff,{nhx,nhy}});
                        //parent[nhx][nhy]= {hx,hy};
                    }
                }
            }
            
        }
        return eff[n-1][m-1]== INT_MAX? 0: eff[n-1][m-1];
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n,m; cin>>n>>m;
        vector<vector<int>> heights;
       
        for(int i=0; i<n; ++i){
            vector<int> temp;
            for(int j=0; j<m; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            heights.push_back(temp);
        }
       
        Solution obj;
        cout<<obj.MinimumEffort(heights)<<"\n";
    }
    return 0;
}
// } Driver Code Ends