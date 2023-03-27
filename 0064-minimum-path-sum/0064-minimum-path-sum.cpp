class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,0));
        
        dp[0][0]=grid[0][0];
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int left=INT_MAX,up=INT_MAX;
                if(i-1>=0){
                    left= dp[i-1][j];
                }
                if(j-1>=0){
                    up= dp[i][j-1];
                }
                if(!(i==0 && j==0))
                dp[i][j]= min(left, up)+ grid[i][j];
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }
        return dp[m-1][n-1];
    }
};