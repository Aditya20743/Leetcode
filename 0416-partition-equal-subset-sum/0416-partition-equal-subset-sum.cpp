class Solution {
public:
    bool helper(int i,int curr,int sum,vector<int>&nums, vector<vector<int>>&dp){
        int n=nums.size();
        
        if(curr>sum)    return false;
        
        if(i==n-1 ){
            if(curr== sum)  return true;
            else return false;
        }
        if(dp[i][curr]!=-1)   return dp[i][curr];
        
        int take= helper(i+1, curr+nums[i], sum,nums,dp);
        int not_take= helper(i+1, curr, sum, nums, dp);
        
        return dp[i][curr]= take || not_take;
    }
    
    bool check(int sum, vector<int>&nums){
        int n=nums.size();
        vector<vector<int>> dp(n,vector<int>(sum+1,-1));

        return helper(0,0,sum,nums,dp);
    }
    
    bool canPartition(vector<int>& nums) {
        int tsum=0;
        for(auto it: nums)  tsum+= it;
        
        if(tsum%2==1)   return false;
        
        return check(tsum/2, nums);
    }
};