class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&vis,
             vector<vector<int>>& grid1,vector<vector<int>>&grid2,bool &f){
        int n=grid2.size();
        int m=grid2[0].size();
        vis[r][c]=1;
        int dir[5]={-1,0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nr= r+ dir[i];
            int nc= c+ dir[i+1];
            
            if(nr>=0 && nr< n && nc>=0 && nc< m){
                if(!vis[nr][nc] && grid2[nr][nc]==1 ){
                    dfs(nr,nc,vis,grid1,grid2,f);
                    if(grid1[nr][nc]==0 && f==true){
                        f= false;
                    }
                }
            }
        }
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n=grid2.size();
        int m=grid2[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        int subIsland=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                bool f= true;
                if(!vis[i][j] && grid2[i][j]==1 && grid1[i][j]==1){
                    dfs(i,j,vis,grid1,grid2,f);
                    if(f==true){
                        subIsland++;
                    }
                }
            }
        }
        return subIsland;
    }
};