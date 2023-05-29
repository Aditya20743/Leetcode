class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        priority_queue< pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        int n= grid.size();
        
        if(grid[0][0]== 1)  return -1;
        
        pq.push({0,{0,0}});
        
        vector<vector<int>> dis(n,vector<int>(n,INT_MAX));
        dis[0][0]=0;
        
        while(!pq.empty()){
            int r= pq.top().second.first;
            int c= pq.top().second.second;
            int d= pq.top().first;
            pq.pop();
            
            if( r== n-1 && c==n-1 ){
                return d+1 ;
            }
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr= r+i;
                    int nc= c+j;
                    if(!(i== 0 && j==0) && nr>=0 && nc>=0 && nr<n && nc<n ){
                        if(grid[nr][nc]==0 && dis[nr][nc]> dis[r][c] + 1){
                            dis[nr][nc]= dis[r][c] + 1;
                            pq.push({dis[nr][nc],{nr,nc}});
                        }
                    }
                }
            }
        }
        return dis[n-1][n-1] == INT_MAX ? -1 : dis[n-1][n-1];
    }
};