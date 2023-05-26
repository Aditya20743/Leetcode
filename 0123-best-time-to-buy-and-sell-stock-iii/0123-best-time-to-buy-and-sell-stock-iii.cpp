class Solution {
public:
    // 1- buy
    // 0- sell
    
//     int helper(int i,int state, vector<int>& prices,int cap, vector<vector<vector<int>>>&dp){
//         if(i==prices.size())    return 0;
//         if(cap==0)  return 0;
//         if(dp[i][state][cap]!=-1)    return dp[i][state][cap];
//         if(state){
//             return dp[i][state][cap]=max(helper(i+1,0,prices,cap,dp)- prices[i], helper(i+1,1,prices,cap,dp));
//         }
//         else {
//             return dp[i][state][cap]=max(helper(i+1,1,prices,cap-1,dp)+ prices[i], helper(i+1,0,prices,cap,dp));
//         }
    
        
//     }
    
    int maxProfit(vector<int>& prices) {
        int n= prices.size();
        
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        
        // find dp[0][1][2];
        dp[0][0][0]=0;
        for(int i=0;i<3;i++){
            dp[0][0][i]=0;
            dp[n][0][i]=0;
            dp[n][1][i]=0;
        }
        
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<2;j++){
                for(int k=1;k<3;k++){
                    if(j==1){
                        int buy= -prices[i]+ dp[i+1][0][k];
                        int nbuy= dp[i+1][1][k];
                        dp[i][j][k]= max(buy,nbuy);
                    }
                    else{
                        int sell= prices[i]+ dp[i+1][1][k-1];
                        int nsell= dp[i+1][0][k];
                        dp[i][j][k]= max(sell,nsell);
                    }
                    
                }
            }
        }
        return dp[0][1][2];
        
        
    }
//         int n=prices.size();
//         // dp[day][state][capacity]  -- max profit in such case.
        
//         vector<vector<vector<int>>> dp(n+1,
//             vector<vector<int>>(2,vector<int>(3,0)));
        
//         //return helper(0,1,prices, 2,dp);   memoization soln function
        
//         for(int k=0;k<3;k++){
//             dp[0][0][k]=0;
//             dp[n][1][k]=0;
//             dp[n][0][k]=0;
//         }
        
//         // base case states the values to be zero which are already there in this case as we are initializing the dp with 0 so no need to write such conditions
        
        
//         for(int i=n-1;i>=0;i--){
            
//             for(int j=0;j<2;j++){
                
//                 for(int k=1;k<3;k++){
//                     // k=0 all values are 0 so, we dont consider it, even if we consider it nothing changes.
                    
//                     if(j){
//                         dp[i][j][k]= max(dp[i+1][0][k]- prices[i], dp[i+1][1][k]);
//                     }
//                     else{
                        
//                             // when we sell, we are left with 1 less than earlier case.
//                         dp[i][j][k]= max(dp[i+1][1][k-1]+ prices[i], 
//                                             dp[i+1][0][k]);
//                     }
//                 }
//             }
//         }

//         return dp[0][1][2];
//         // started with 1st day, buy stock, and 2 transactions.
        
        
//     }
    

};