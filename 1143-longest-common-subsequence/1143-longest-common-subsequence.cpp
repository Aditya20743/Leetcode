class Solution {
public:
//     int helper(int i,int j, string text1, string text2, vector<vector<int>>&dp){
//         int n= text1.size();
//         int m= text2.size();
        
//         if(i==n || j==m)    return 0;
        
//         if(dp[i][j]!= -1)   return dp[i][j];
        
//         if(text1[i]==text2[j]){
//             return dp[i][j]=1+helper(i+1,j+1,text1, text2,dp);
//         }
//         return dp[i][j]=max(helper(i+1, j,text1, text2,dp), helper(i,j+1, text1, text2,dp));
//     }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n= text1.size();
        int m= text2.size();
        
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i==n || j==m){
                    dp[n][m]=0;
                }
                else if(text1[i]== text2[j]){
                    dp[i][j]= dp[i+1][j+1]+1;
                }
                else{
                    dp[i][j]=max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }
        
        return dp[0][0];
    }
};