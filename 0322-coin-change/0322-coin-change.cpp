class Solution {
public:
    int helper(vector<int>& coins, int idx, int amount,vector<vector<int>>&dp){
        if(idx==0){
           if(amount%coins[0]==0){
            return amount/coins[idx];
           }
            else return 1e9;
        }
        if(dp[idx][amount]!= -1)    return dp[idx][amount];
        int take= 1e9;
        int not_take= helper(coins, idx-1, amount,dp);
        if(amount>= coins[idx]){
            take= helper(coins,idx,amount-coins[idx],dp)+1;
        }
        return dp[idx][amount]=min(take,not_take);
        
    }
    int coinChange(vector<int>& coins, int amount) {
        int n= coins.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        
        return helper(coins,n,amount, dp) >= 1e9 ? -1: helper(coins,n,amount, dp);
       
    }
};