class Solution {
public:
    int dir[5]={-1,0,1,0,-1};
    
    void dfs(int r,int c, vector<vector<int>>&grid, vector<vector<int>>&vis){
        vis[r][c]=1;
        
        int row= grid.size();
        int col= grid[0].size();
        
        for(int i=0;i<4;i++){
            int nr= r+dir[i];
            int nc= c+dir[i+1];
            
            if(nr>=0 && nr<row && nc>=0 && nc<col){
                if(vis[nr][nc]==0 && grid[nr][nc]==0){
                    dfs(nr,nc,grid,vis);
                }
            }
        }
        
    }
    int closedIsland(vector<vector<int>>& grid) {
        int open_islands=0;
        int closed_islands=0;
        
        int row= grid.size();
        int col= grid[0].size();
        
        vector<vector<int>> vis(row,vector<int>(col,0));
        
        for(int i=0;i<row;i++){
            if(grid[i][0]==0 && vis[i][0]==0){
                dfs(i,0,grid,vis);
            }
            if(grid[i][col-1]==0 && vis[i][col-1]==0){
                dfs(i,col-1, grid,vis);
            }
        }
        
         for(int i=0;i<col;i++){
            if(grid[0][i]==0 && vis[0][i]==0){
                dfs(0,i,grid,vis);
            }
            if(grid[row-1][i]==0 && vis[row-1][i]==0){
                dfs(row-1,i, grid,vis);
            }
        }
        
    
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(vis[i][j]==0 && grid[i][j]==0){
                    dfs(i,j,grid,vis);
                    closed_islands++;
                } 
            }
        }
        return closed_islands;
    }
};