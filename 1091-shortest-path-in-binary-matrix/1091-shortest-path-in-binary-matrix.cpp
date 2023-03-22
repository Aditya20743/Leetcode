class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0]!= 0)  return -1;
        int n= grid.size();
        int m= grid[0].size();
        
        vector<vector<int>> dis(n,vector<int>(m,INT_MAX));
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>> > pq;
        pq.push({1,{0,0}});
        dis[0][0]=1;
        while(!pq.empty()){
            int dist= pq.top().first;
            int row= pq.top().second.first;
            int col= pq.top().second.second;
            pq.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr= row+ i;
                    int nc= col+ j;
                    if( nr>=0 && nc>=0 && nr<n && nc<m){
                        if(grid[nr][nc]==0 && dis[nr][nc]> dist+1){
                            dis[nr][nc]=dist+1;
                            pq.push({dist+1,{nr,nc}});
                        }
                    }
                }
            }
        }
        if(dis[n-1][m-1]==INT_MAX)  return -1;
        return dis[n-1][m-1];
        
    }
};