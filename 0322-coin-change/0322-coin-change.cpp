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
        
        int n=coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<=amount;j++){
                if(i==0){
                    if(j%coins[i]==0)   dp[i][j]=j/coins[i];
                    else dp[i][j]=1e9;
                }
                else{
                int take =INT_MAX;
                int notTake= dp[i-1][j];
                if(j>=coins[i])  take= dp[i][j-coins[i]]+1;
                dp[i][j]=min(take,notTake); 
                } 
            }
        }
        return dp[n-1][amount]>=1e9 ? -1 : dp[n-1][amount]; 
    }
};