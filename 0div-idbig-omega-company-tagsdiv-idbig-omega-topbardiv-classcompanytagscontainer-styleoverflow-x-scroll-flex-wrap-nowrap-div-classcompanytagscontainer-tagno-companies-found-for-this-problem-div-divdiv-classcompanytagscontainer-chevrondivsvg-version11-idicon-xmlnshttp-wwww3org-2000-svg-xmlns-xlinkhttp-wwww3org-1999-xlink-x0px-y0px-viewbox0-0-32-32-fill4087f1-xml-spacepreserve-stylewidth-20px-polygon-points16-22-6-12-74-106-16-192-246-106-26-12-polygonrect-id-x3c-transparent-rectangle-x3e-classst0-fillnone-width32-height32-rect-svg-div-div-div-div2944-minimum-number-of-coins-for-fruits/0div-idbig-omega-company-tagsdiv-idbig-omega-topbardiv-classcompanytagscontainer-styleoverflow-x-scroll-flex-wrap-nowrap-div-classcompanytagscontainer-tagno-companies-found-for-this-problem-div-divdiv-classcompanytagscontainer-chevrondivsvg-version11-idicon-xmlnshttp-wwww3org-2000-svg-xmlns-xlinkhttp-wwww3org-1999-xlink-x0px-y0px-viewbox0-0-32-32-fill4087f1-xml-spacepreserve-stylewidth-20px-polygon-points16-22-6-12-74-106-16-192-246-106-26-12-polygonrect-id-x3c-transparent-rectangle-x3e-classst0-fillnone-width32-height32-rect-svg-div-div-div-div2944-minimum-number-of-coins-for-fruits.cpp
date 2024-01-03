class Solution {
public:
    int helper(int i, vector<int>& prices, int free, vector<vector<int>>&dp){
        
        if(i>prices.size()){
            return 0;
        }
        
        if(dp[i][free]!= -1)    return dp[i][free];
        
        if(free){
            int take= helper(i+1, prices, i,dp)+ prices[i-1];
            
            int not_take= helper(i+1, prices, free-1,dp);
            
            return dp[i][free]=min(take, not_take);
        }
        
        return dp[i][free]=helper(i+1, prices, i,dp)+ prices[i-1];
    }
    
    int minimumCoins(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+2, vector<int>(prices.size()+2, -1));
        return helper(1,prices, 0,dp);
    }
};