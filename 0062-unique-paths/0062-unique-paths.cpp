class Solution {
public:
    int helper(int i,int j, int m,int n, vector<vector<int>>& dp){
        if(i>m || j>n){
            return 0;
        }
        else if(i==m && j==n){
            return 1;
        }
        if(dp[i][j]!= -1)   return dp[i][j];
        
        int right= helper(i, j+1,m,n,dp);
        int left= helper(i+1,j,m,n,dp);
        
        return dp[i][j]=right+left;
    }
    
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m+1,vector<int>(n+1,-1));
        int ans= helper(1,1,m,n,dp);
        
        return ans;
    }
};