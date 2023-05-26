class Solution {
public:
//     int helper(int i, vector<int>&prices, int s,vector<vector<int>>&dp){
//         if(i== prices.size()){
//             return 0;
//         }
//         int sell =0, not_sell =0;
        
//         if(dp[i][s]!= -1)   return dp[i][s];
        
//         if(s==0){
            
//             int buy= -prices[i]+ helper(i+1 ,prices, 1,dp);
//             int not_buy= helper(i+1, prices, 0,dp);
            
//             return dp[i][0]=max(buy,not_buy);
//         }
//         else{
//             sell= prices[i]+ helper(i+1,prices, 0,dp);
//             not_sell= helper(i+1, prices, 1,dp);
//         }
//         return dp[i][1]=max(sell,not_sell);
//     }
    
    int maxProfit(vector<int>& prices) {
        // 0 -> buy     1-> Sell
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,0));
        // return helper(0,prices,0,dp);
        int n= prices.size();
        dp[n][0]=0;
        dp[n][1]=0;
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                
                if(j==0){
                    int buy= dp[i+1][1] + -prices[i];
                    int notbuy= dp[i+1][0];
                    dp[i][j]= max(buy, notbuy);
                }
                else {
                    int sell= dp[i+1][0] + prices[i];
                    int notsell= dp[i+1][1];
                    dp[i][j]= max(sell, notsell);
                }
            }
        }
        
        return dp[0][0];
    }
};