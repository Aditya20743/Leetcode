class Solution {
public:
    //1 - buy 
    //0- sell
    int helper(int i, int state, vector<int>& prices,vector<vector<int>>&dp ){
        if(i== prices.size())   return 0;
        if(dp[i][state]!=-1)    return dp[i][state];
        if(state){
            return dp[i][state]= max( -prices[i]+ helper(i+1,0,prices,dp), helper(i+1,1,prices,dp));
        }
        else{
            return dp[i][state]= max( +prices[i]+ helper(i+1,1,prices,dp), helper(i+1,0,prices,dp));
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size()+1, vector<int>(2,-1));
        return helper(0,1,prices,dp);
    }
};