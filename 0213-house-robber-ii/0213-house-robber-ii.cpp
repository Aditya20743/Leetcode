class Solution {
public:
    int helper(int i,int n,vector<int>&nums,vector<int>&dp){
        if(i>n) return 0;
        
        if(dp[i]!= -1)  return dp[i];
        
        int take= helper(i+2,n,nums,dp)+nums[i];
        int not_take= helper(i+1,n,nums,dp);
        
        return dp[i]= max(take,not_take);
    }
    int helper2(int i,int n,vector<int>&nums,vector<int>&dp2){
        if(i>n) return 0;
        
        if(dp2[i]!= -1)  return dp2[i];
        
        int take= helper(i+2,n,nums,dp2)+nums[i];
        int not_take= helper(i+1,n,nums,dp2);
        
        return dp2[i]= max(take,not_take);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        
        if(n==1)    return nums[0];
        
        vector<int> dp(n,-1);
        
        int first= helper(0,n-2,nums,dp);
        
        vector<int> dp2(n,-1);
        int second= helper2(1,n-1,nums,dp2);
        
        return max(first, second);
    }
};