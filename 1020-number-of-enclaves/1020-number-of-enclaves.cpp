class Solution {
public:
    void dfs(int r,int c, vector<vector<int>>&vis,
             vector<vector<int>>&grid){
        
        int n=grid.size();
        int m= grid[0].size();
        
        vis[r][c]=1;
        
        int dir_r[4]={0,1,0,-1};
        int dir_c[4]={1,0,-1,0};
        
        for(int i=0;i<4;i++){
            int newrow= r + dir_r[i];
            int newcol= c + dir_c[i];
            
            if(newrow>=0 && newrow<n && newcol>=0 && newcol<m){
                if(!vis[newrow][newcol] && grid[newrow][newcol]==1){
                    dfs(newrow,newcol,vis,grid);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m= grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( (j==0 || j== m-1 ||i==0 || i== n-1) &&
                   !vis[i][j] && grid[i][j]==1){
                    dfs(i,j,vis,grid);
                }
            }
        }
        
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if( !vis[i][j] && grid[i][j]==1){
                    count++;
                }
            }
        }
        return count;
    }
};