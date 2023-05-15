class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        int m=triangle[n-1].size();
        
        vector<vector<int>> dp(n,vector<int>(m,0));
        
        for(int i=0;i<n;i++){
            dp[i].resize(i+1);
        }
        dp[0][0]= triangle[0][0];
        
        for(int i=0;i<n;i++){
            for(int j=0;j<=i;j++){
                
                if(j==0 && i>0){
                    dp[i][j]= triangle[i][j]+ dp[i-1][j]; 
                }
                else if(j==i && j>0){
                    dp[i][j]= triangle[i][j]+ dp[i-1][j-1];
                }
                else if(i>0 && j>0){
                    dp[i][j]= min(dp[i-1][j],dp[i-1][j-1]) + triangle[i][j];
                }
            }
        }
        int ans=INT_MAX;
        for(int j=0;j<m;j++){
            ans= min(ans, dp[n-1][j]);
        }
        
        // for(int i=0;i<n;i++){
        //     for(int j=0;j<=i;j++){
        //         cout<<dp[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        
        return ans;
    }
};