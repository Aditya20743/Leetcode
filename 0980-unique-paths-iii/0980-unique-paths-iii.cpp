class Solution {
public:
    // 1 starting square
    // 2 ending square
    // 0 empty
    // -1 obstacles
    bool check(vector<vector<int>> vis,vector<vector<int>> grid){
        int m= grid.size();
        int n= grid[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==0){
                    return false;
                }
            }
        }
        return true;
    }
    
    int helper(vector<vector<int>>& grid, int sx,int sy, int dx,int dy,vector<vector<int>> vis){
        int m= grid.size();
        int n= grid[0].size();
        if(sx>=m || sy>=n || sx<0 || sy<0  ){
            return 0;
        }
        
        if(grid[sx][sy]==-1){
            return 0;
        }
        if(vis[sx][sy]==1){
            return 0;
        }
        
        vis[sx][sy]=1;
        
        if(sx==dx && sy==dy && check(vis,grid)){
            return 1;
        }
        int down=0, up=0, left=0, right=0;
        
        // if(vis[sx+1][sy]==0)
        down= helper(grid, sx+1, sy, dx,dy, vis);
        
        // if(vis[sx][sy+1]==0)
        right= helper(grid,sx,sy+1,dx,dy,vis);
        
        left= helper(grid,sx,sy-1,dx,dy,vis);
        
        up= helper(grid,sx-1,sy,dx,dy,vis);
        
        return down+up+left+right ;
    }
    
    int uniquePathsIII(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        
        int sx,sy,dx,dy;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    sx=i;
                    sy=j;
                }
                else if(grid[i][j]==2){
                    dx=i;
                    dy=j;
                }
            }
        }
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        return helper(grid,sx,sy,dx,dy,vis);
    }
};