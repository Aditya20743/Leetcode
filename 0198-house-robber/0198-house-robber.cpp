class Solution {
public:
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>dp(n+2,0);
        for(int i=n-1;i>=0;i--){
            int pick= nums[i];
            //if(i<n-1)
                pick+= dp[i+2];
            
            int not_pick= 0;
            not_pick+= dp[i+1];
            dp[i]= max(pick,not_pick);
        }
        return dp[0];
    }
};