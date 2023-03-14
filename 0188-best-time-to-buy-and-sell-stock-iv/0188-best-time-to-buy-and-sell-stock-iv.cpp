class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(k+1,0)));
        
        // base case states the values to be zero which are already initialised
        // 1= buy   0= sell
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int h=1;h<=k;h++){
                    if(j==1){
                        dp[i][j][h]= max(dp[i+1][0][h]- prices[i], dp[i+1][1][h]);
                    }
                    else {
                        dp[i][j][h]= max(dp[i+1][1][h-1]+ prices[i],dp[i+1][0][h]);
                    }
                }
            }
        }
        return dp[0][1][k];
    }
};