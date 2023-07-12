class Solution {
public:
    int helper(int idx, vector<int>&nums,int last, vector<vector<int>>&dp){
        if(idx==nums.size()){
            return 0;
        }
        if(dp[idx][last+1]!= -1)  return dp[idx][last+1];
        
        int take= 0, not_take=0;
        
        not_take= helper(idx+1, nums, last, dp);
        
        if(last==-1){
            take= helper(idx+1, nums, idx,dp)+1;
        }
        else if(nums[idx]> nums[last])  
            take= helper(idx+1, nums, idx,dp)+1;
        
        return dp[idx][last+1]= max(take,not_take);
        
    }
    int lengthOfLIS(vector<int>& nums) {
        int maxi= 0;
        
        int n= nums.size();
        
        vector<vector<int>> dp(n,vector<int>(n+1,-1));
        
        return helper(0, nums,-1,dp);
        
    }
};