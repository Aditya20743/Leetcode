class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) 
    {
        int n = piles.size();
        vector<vector<int>>dp(n, vector<int>(k + 1, 0)); 
        //for considering [number of piles = n]
        //we must already have answers for [number of piles = (n - 1)]
        //thus we need to go bottom up
        //we need to go from [no. of piles under consideration = 1 to n]
        
        //consider only (endPileIdx + 1) number of piles at a time
        for (int endPileIdx = 0; endPileIdx < n; endPileIdx++) //count of piles = endPileIdx + 1
        {
            int currPileSize = piles[endPileIdx].size();
            for (int coinsToPick = 1; coinsToPick <= k; coinsToPick++)
            {
                //=============================================================================
                //DON'T PICK ANY COIN FROM CURR PILE
                int maxSum = (endPileIdx - 1 < 0)? 0 : dp[endPileIdx - 1][coinsToPick];  
                
                int maxCanPick = min(coinsToPick, currPileSize);
                int pickedSum = 0;
                //now consider picking some coins
                for (int i = 0; i < maxCanPick; i++)
                {
                    int coinValue = piles[endPileIdx][i];
                    pickedSum += coinValue;
                    
                    int nextMaxSum = 0;
                    if (endPileIdx > 0) 
                        nextMaxSum = dp[endPileIdx - 1][coinsToPick - i - 1];
                    maxSum = max(maxSum, pickedSum + nextMaxSum);
                }
                //=======================================================================================
                dp[endPileIdx][coinsToPick] = maxSum;
            }
        }
        return dp[n - 1][k];
    }
};