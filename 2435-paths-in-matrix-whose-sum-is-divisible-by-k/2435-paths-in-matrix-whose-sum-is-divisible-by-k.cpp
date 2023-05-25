class Solution {
public:
    int helper(int i, int j, int lastr, int k, vector<vector<int>>& grid,vector<vector<vector<int>>>&dp){
        int mod= 1e9+7;
        int m= grid.size();
        int n= grid[0].size();
        
        if(i== m-1 && j== n-1){
            if((lastr+ grid[i][j])%k==0)    return 1;
            else return 0;
        }
        if(i >= m || j>= n || i<0 || j<0)   return 0;
        
        if(dp[i][j][lastr]!= -1)    return dp[i][j][lastr];
        
        return dp[i][j][lastr]=(helper(i+1,j,(lastr+grid[i][j]%k)%k, k, grid,dp)+
                helper(i,j+1,(lastr+grid[i][j]%k)%k, k, grid,dp)) %mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        int m= grid.size();
        int n= grid[0].size();
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(k,-1) ) );
        
        
        return helper(0,0,0,k,grid,dp);
    }
};