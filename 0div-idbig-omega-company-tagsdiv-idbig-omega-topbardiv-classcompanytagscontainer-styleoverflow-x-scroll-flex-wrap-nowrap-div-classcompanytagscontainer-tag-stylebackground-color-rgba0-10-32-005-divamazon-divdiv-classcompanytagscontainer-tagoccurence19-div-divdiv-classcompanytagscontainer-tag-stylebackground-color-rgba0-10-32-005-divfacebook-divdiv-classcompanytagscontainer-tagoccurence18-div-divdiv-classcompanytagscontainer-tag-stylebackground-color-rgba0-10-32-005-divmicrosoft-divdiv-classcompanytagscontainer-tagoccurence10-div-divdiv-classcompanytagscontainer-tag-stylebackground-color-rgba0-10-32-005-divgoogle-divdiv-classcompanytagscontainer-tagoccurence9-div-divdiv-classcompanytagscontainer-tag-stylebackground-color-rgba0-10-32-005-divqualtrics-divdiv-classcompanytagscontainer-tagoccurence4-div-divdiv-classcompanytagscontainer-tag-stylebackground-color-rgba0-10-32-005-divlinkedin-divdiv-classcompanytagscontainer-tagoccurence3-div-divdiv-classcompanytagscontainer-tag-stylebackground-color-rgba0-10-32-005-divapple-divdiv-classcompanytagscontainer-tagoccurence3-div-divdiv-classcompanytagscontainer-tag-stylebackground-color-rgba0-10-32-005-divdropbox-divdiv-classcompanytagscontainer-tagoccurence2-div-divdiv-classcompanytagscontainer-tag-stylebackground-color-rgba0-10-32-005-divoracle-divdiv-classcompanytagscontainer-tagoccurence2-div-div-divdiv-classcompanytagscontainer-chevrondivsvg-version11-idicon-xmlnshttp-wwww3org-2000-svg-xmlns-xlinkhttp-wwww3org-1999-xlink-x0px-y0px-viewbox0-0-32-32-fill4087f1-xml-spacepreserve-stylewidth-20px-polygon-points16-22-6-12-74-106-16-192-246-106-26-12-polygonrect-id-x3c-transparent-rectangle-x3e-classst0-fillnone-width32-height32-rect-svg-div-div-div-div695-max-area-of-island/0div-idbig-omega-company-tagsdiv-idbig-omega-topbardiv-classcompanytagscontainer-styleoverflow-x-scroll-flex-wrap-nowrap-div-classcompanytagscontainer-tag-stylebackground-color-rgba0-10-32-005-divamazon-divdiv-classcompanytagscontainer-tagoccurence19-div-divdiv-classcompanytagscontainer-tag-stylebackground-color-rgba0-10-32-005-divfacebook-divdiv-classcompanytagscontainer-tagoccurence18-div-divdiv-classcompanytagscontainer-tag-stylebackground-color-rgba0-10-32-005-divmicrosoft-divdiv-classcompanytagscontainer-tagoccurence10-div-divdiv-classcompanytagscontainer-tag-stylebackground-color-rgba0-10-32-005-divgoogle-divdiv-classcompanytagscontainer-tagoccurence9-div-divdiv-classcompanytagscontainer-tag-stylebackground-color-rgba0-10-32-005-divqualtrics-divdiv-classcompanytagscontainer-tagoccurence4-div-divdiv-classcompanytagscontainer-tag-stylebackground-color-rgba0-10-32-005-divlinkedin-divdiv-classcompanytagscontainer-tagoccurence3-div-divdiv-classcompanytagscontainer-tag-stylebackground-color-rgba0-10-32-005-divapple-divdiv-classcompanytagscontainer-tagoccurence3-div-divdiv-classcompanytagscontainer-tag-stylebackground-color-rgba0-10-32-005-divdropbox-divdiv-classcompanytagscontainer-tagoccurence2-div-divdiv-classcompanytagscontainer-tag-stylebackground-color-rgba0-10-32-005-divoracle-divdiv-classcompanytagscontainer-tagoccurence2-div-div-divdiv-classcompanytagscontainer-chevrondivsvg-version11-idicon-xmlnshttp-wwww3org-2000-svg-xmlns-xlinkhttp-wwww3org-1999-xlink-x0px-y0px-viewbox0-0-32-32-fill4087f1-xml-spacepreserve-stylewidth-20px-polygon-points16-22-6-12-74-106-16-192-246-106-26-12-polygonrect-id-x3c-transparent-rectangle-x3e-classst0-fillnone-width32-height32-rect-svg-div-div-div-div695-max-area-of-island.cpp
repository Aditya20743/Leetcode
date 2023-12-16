class Solution {
public:
    int bfs(int i,int j, vector<vector<int>>&vis, vector<vector<int>>&grid){
        vis[i][j] = 1;
        int n= grid.size();
        int m= grid[0].size();
        
        int land=0;
        
        queue<pair<int,int>> q;
        q.push({i,j});
        
        int xdir[4]= {-1,0,1,0};
        int ydir[4]= {0,1,0,-1};
        
        while(!q.empty()){
            int x= q.front().first;
            int y= q.front().second;
            q.pop();
            land++;
            
            vis[x][y] = 1;
            
            for(int it=0;it<4;it++){
                int nx= x+xdir[it];
                int ny= y+ydir[it];
                
                if(nx>=0 && ny>=0 && nx<n && ny<m){
                    if(vis[nx][ny]==-1 && grid[nx][ny]==1){
                        vis[nx][ny] = 1;
                        q.push({nx,ny});
                    }
                }
            }
        }
        return land;
    }
    
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        vector<vector<int>>vis(n,vector<int>(m,-1));
        
        int count=0;
        int maxi = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]==-1 && grid[i][j]==1){
                
                    count = bfs(i,j,vis, grid);
                    maxi= max(maxi, count);
                    vis[i][j] = 1;
                }
            }
        }
        
        return maxi;
    }
};