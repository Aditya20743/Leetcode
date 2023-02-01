class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& vis, vector<vector<char>>&grid){
        int m= grid.size();
        int n=grid[0].size();
        vis[r][c]=1;
        
        int dir[5]={-1,0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr= dir[i]+ r;
            int nc= dir[i+1] + c;
            if(nr>=0 && nc>=0 && nr< m && nc<n){
                if(!vis[nr][nc] && grid[nr][nc]=='1'){
                    dfs(nr,nc,vis,grid);
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m= grid.size();
        int n=grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        int count=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]=='1'){
                    dfs(i,j,vis,grid);
                    count++;
                }
            }
        }
        return count;
    }
};