class Solution {
public:
    int dp[51][51];
    int solve(vector<vector<int>> &grid,vector<vector<int>>& moveCost,int i,int j,int n,int m){
        if(i==n-1){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        for(int k=0;k<m;k++){
            ans=min(ans,grid[i][j]+moveCost[grid[i][j]][k]+solve(grid,moveCost,i+1,k,n,m));
        }
        return dp[i][j]=ans;
    }
    int minPathCost(vector<vector<int>>& grid, vector<vector<int>>& moveCost) {
        int ans=INT_MAX;
        int n=grid.size();
        int m=grid[0].size();
        memset(dp,-1,sizeof dp);
        for(int i=0;i<m;i++){
            ans=min(ans,solve(grid,moveCost,0,i,n,m));
        }
        return ans;
    }
};