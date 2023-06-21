class Solution {
public:
    bool helper(int idx, int curr, vector<int>&nums, int sum, vector<vector<int>>&dp){
        if(curr>sum)    return false;
        
        if(curr==sum)   return true;
        
        if(idx==nums.size()){
            return false;
        }
        if(dp[idx][curr]!= -1)   return dp[idx][curr];
        
        int take= helper(idx+1, nums[idx]+curr, nums, sum,dp);
        int not_take= helper(idx+1, curr, nums,sum,dp);
        
        return dp[idx][curr]= take|not_take;
        
        
    }
    
    bool canPartition(vector<int>& nums) {
        // => find a subsquence with sum = sum/2;
        
        int sum=0;
        for(auto it: nums){
            sum+= it;
        }
        
        if(sum%2){
            return false;
        }
        vector<vector<int>> dp(nums.size(),vector<int>(sum/2+1,-1));
        
        return helper(0,0, nums,sum/2 ,dp);
    }
};