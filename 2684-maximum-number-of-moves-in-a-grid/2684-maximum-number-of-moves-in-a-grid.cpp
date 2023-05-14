class Solution {
public:
    int dfs(int r,int c,vector<vector<int>>&grid, vector<vector<int>>&dp){
        int m=grid.size();
        int n=grid[0].size();
        int temp=0;
      
        for(int i=-1;i<=1;i++){
            int nr= r+ i;
            int nc= c+1;
            if(nr>=0 && nc<n && nr<m && grid[nr][nc]> grid[r][c] ){
                if(dp[nr][nc]!=-1){
                    temp= max(temp,dp[nr][nc]);
                }
                else
                    temp=max(temp,dp[nr][nc]=dfs(nr,nc,grid,dp));
            }
        }
        return temp+1;
        
    }
    
    
    int maxMoves(vector<vector<int>>& grid) {
        int maxi=0;
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        for(int i=0;i<grid.size();i++){
            maxi=max(dfs(i,0,grid,dp), maxi);
        }
        return maxi-1;
    }
};