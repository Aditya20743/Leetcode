class Solution {
public:
    int helper(int i, int prev, vector<int>&nums, vector<vector<int>>&dp){
        if(i>= nums.size()){
            return 0;
        }
        if( dp[i][prev+1]!= -1)    return dp[i][prev+1];
        
        int take =0, not_take=0;
        
        if( prev==-1 || nums[prev]< nums[i]){
            take= helper(i+1, i, nums,dp)+1;
        }
        not_take = helper(i+1, prev, nums,dp);
        
        return dp[i][prev+1]= max(take, not_take);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n= nums.size();
        vector<vector<int>> dp(n, vector<int>(n+1,-1));
        return helper(0,-1,nums,dp );
    }
};