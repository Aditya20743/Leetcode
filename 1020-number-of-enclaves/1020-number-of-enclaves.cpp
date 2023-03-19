class Solution {
public:
    void dfs(int r,int c, vector<vector<int>>&grid, vector<vector<int>>&vis){
        int m= grid.size();
        int n= grid[0].size();
        
        vis[r][c]=1;
        int dir[5]={-1,0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nr= dir[i]+ r;
            int nc= c+ dir[i+1];
            
            if(nr>=0 && nr<m && nc>=0 && nc<n){
                if(grid[nr][nc]==1 && vis[nr][nc]==0){
                    dfs(nr,nc, grid,vis);
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && (i==0 || j==0 || i==m-1 || j==n-1)){
                    dfs(i,j,grid,vis);
                }
            }
        }
        int count=0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && vis[i][j]==0){
                    count++;
                }
            }
        }
        return count;
    }
};

// class Solution {
// public:
    
    
//     void solve(vector<vector<char>>& board) {
//         int m= board.size();
//         int n= board[0].size();
        
//         vector<vector<int>>vis(m,vector<int>(n,0));
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(board[i][j]=='O' && (i==0 || j==0 || i==m-1 || j==n-1)){
//                     dfs(i,j,board,vis);
//                 }
//             }
//         }
        
//         for(int i=0;i<m;i++){
//             for(int j=0;j<n;j++){
//                 if(board[i][j]=='O' && vis[i][j]==0){
//                     board[i][j]='X';
//                 }
//             }
//         }
//     }
// };