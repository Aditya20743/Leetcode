class Solution {
public:
    void dfs(int r,int c,vector<vector<int>> &vis, vector<vector<int>>& grid){
        int m= grid.size();
        int n= grid[0].size();
        vis[r][c]=1;
        grid[r][c]=2;
        int dir[5]={-1,0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nr= r+ dir[i];
            int nc= c+ dir[i+1];
            
            if(nr>=0 && nc>=0 && nr< m && nc< n){
                if(!vis[nr][nc] && grid[nr][nc]==0){
                    dfs(nr,nc,vis,grid);
                }
            }
        }
    }
    int closedIsland(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0 && ((i== m-1) || (i==0) || (j== 0) || (j== n-1) )){
                    dfs(i,j,vis,grid);
                    //grid[i][j]=1;
                }
            }
        }
        
        
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==0){
                    dfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};