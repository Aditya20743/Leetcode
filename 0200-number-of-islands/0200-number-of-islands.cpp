class Solution {
public:
    int dir[5] = {-1,0,1,0,-1};
    
    void dfs(int i,int j,vector<vector<char>>& grid, vector<vector<int>>&vis ){
        vis[i][j]=1;
        
        int n= grid.size();
        int m= grid[0].size();
        
        for(int x=0;x<4;x++){
            int ni= dir[x]+ i;
            int nj= dir[x+1]+ j;
            
            if(ni>=0 && nj>=0 && ni<n && nj<m ){
                if(vis[ni][nj]==-1 && grid[ni][nj]=='1'){
                    vis[ni][nj]=1;
                    dfs(ni,nj,grid, vis);
                }
            }
        }
        
    }
    
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        vector<vector<int>> vis(n, vector<int>(m,-1));
        
        int islands=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(vis[i][j]== -1 && grid[i][j]=='1'){
                    dfs(i,j,grid,vis);
                    islands++;
                }
            }
        }
        
        return islands;
    }
};