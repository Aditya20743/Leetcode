class Solution {
public:
    int helper(int idx, vector<int>& nums, int amount,vector<int>&dp){
        if(idx<0) return 0;
        if(dp[idx]!= -1)    return dp[idx];
        
        int not_pick= helper(idx-1, nums,amount,dp);
        int pick= nums[idx] + helper(idx-2,nums,amount,dp);
        
        return dp[idx]=max(pick, not_pick);
        
    }
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(nums.size()+1,-1);
        return helper(n-1,nums,0,dp);
    }
};