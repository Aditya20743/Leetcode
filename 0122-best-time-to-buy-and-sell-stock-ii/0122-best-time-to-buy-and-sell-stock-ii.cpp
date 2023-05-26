class Solution {
public:
    int helper(int i, vector<int>&prices, int s,vector<vector<int>>&dp){
        if(i== prices.size()){
            return 0;
        }
        int sell =0, not_sell =0;
        
        if(dp[i][s]!= -1)   return dp[i][s];
        
        if(s==0){
            
            int buy= -prices[i]+ helper(i+1 ,prices, 1,dp);
            int not_buy= helper(i+1, prices, 0,dp);
            
            return dp[i][0]=max(buy,not_buy);
        }
        else{
            sell= prices[i]+ helper(i+1,prices, 0,dp);
            not_sell= helper(i+1, prices, 1,dp);
        }
        return dp[i][1]=max(sell,not_sell);
    }
    
    int maxProfit(vector<int>& prices) {
        // 0 -> buy     1-> Sell
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return helper(0,prices,0,dp);
    }
};