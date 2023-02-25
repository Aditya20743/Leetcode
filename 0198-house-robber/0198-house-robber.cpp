class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int> dp(n);
        
        // dp[i] will store max money robbed till index i
        
        // if only one house => we will rob it. 
        dp[0]= nums[0]; 
    
        // start from index 1 till last house index
        // each house can be robbed or skipped
        
        for(int i=1;i<n;i++){
            // if house is robbed, then money of that house (nums[i]) will be added to amount robbed till now that is (dp[i-2]) because we can rob house consecutively  
            
            int pick= nums[i];
            // if house is not robbed/picked, dp[i] = dp[i-1]
            int not_pick= dp[i-1];
            if(i>=2)    
            // if i<2 then there will be not money robbed so we will add dp[i-2] only whe i>=2
                pick+= dp[i-2];
            dp[i]= max(pick , not_pick);
        }
        // finally we will return max money robbed till dp[n-1]
        return dp[n-1];
    }
};