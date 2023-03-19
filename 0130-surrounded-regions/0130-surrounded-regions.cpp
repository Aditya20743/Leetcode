class Solution {
public:
    void dfs(int r,int c, vector<vector<char>>&board, vector<vector<int>>&vis){
        int m= board.size();
        int n= board[0].size();
        
        vis[r][c]=1;
        int dir[5]={-1,0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nr= dir[i]+ r;
            int nc= c+ dir[i+1];
            
            if(nr>=0 && nr<m && nc>=0 && nc<n){
                if(board[nr][nc]=='O' && vis[nr][nc]==0){
                    dfs(nr,nc, board,vis);
                }
            }
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int m= board.size();
        int n= board[0].size();
        
        vector<vector<int>>vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && (i==0 || j==0 || i==m-1 || j==n-1)){
                    dfs(i,j,board,vis);
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]=='O' && vis[i][j]==0){
                    board[i][j]='X';
                }
            }
        }
    }
};