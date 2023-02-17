class Solution {
public:
//     int minCost(int idx, vector<int>&cost){
//         int dp[cost.size()+1];
//         dp[1]=cost[0];
//         dp[2]= cost[1];
//         for(int i=3;i<cost.size();i++){
//             dp[i]= min(dp[i-1],dp[i-2]) + cost[i-1];
//         }
//         return min(dp[cost.size()-1], dp[cost.size()]);
        
//     }
    int minCostClimbingStairs(vector<int>& cost) {
        int n= cost.size();
        int dp[n+1];
        dp[1]=cost[0];
        dp[2]= cost[1];
        for(int i=3;i<=n;i++){
            dp[i]= min(dp[i-1],dp[i-2]) + cost[i-1];
        }
        return min(dp[n-1], dp[n]);
    }
};