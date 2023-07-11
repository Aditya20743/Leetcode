class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m=matrix[0].size();
        
        vector<vector<int>>dp(n,vector<int>(m,0));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                
                if(i==0 ){
                    dp[i][j]= matrix[i][j];
                }
                
                else if(j==0 ){
                    dp[i][j]=  min(dp[i-1][j], dp[i-1][j+1])+ matrix[i][j];
                }
                else if(j==m-1){
                    dp[i][j]= min(dp[i-1][j-1],dp[i-1][j] )+ matrix[i][j];
                }
                
                else if(i>0 && j>0)
                dp[i][j]= min(dp[i-1][j-1], min(dp[i-1][j], dp[i-1][j+1]) )+ matrix[i][j];
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<m;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans=min(dp[n-1][j],ans);
        }
        return ans;
    }
};