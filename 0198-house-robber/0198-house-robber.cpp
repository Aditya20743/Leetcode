class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+1);
        dp[0]= nums[0];
        
        for(int i=1;i<n;i++){
            int pick= nums[i];
            int not_pick= dp[i-1];
            if(i>=2)    
                pick+= dp[i-2];
            dp[i]= max(pick , not_pick);
        }
        return dp[n-1];
    }
};