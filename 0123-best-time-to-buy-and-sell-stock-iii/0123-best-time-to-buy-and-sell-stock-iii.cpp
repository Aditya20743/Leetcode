class Solution {
public:
    // 1- buy
    // 0- sell
    
    int helper(int i,int state, vector<int>& prices,int cap, vector<vector<vector<int>>>&dp){
        if(i==prices.size())    return 0;
        if(cap==0)  return 0;
        if(dp[i][state][cap]!=-1)    return dp[i][state][cap];
        if(state){
            return dp[i][state][cap]=max(helper(i+1,0,prices,cap,dp)- prices[i], helper(i+1,1,prices,cap,dp));
        }
        else {
            return dp[i][state][cap]=max(helper(i+1,1,prices,cap-1,dp)+ prices[i], helper(i+1,0,prices,cap,dp));
        }
    
        
    }
    
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>> dp(n+1,
            vector<vector<int>>(2,vector<int>(3,0)));
        //return helper(0,1,prices, 2,dp);
        for(int k=0;k<3;k++){
            dp[0][0][k]=0;
            dp[n][1][k]=0;
            dp[n][0][k]=0;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=0;k<3;k++){
                    if(j){
                        dp[i][j][k]= max(dp[i+1][0][k]- prices[i], dp[i+1][1][k]);
                    }
                    else{
                        if(k>=1){
                            dp[i][j][k]= max(dp[i+1][1][k-1]+ prices[i], 
                                            dp[i+1][0][k]);
                        }
                        else{
                            dp[i][j][k]= dp[i+1][0][k];
                        }
                    }
                }
            }
        }
//         int ans=0;
            
//         for(int k=0;k<3;k++){
//             ans= max(dp[0][1][k], ans);
//         }
        return dp[0][1][2];
        
        
        
    }
    
//     int maxProfit(vector<int>&p){
//         int n=prices.size();
//         int mini= prices[0];
//         int ans=0, count=0;
//         for(int i=0;i<n;i++){
            
//         }
//     }
};