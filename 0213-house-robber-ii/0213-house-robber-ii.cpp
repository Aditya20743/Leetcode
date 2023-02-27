class Solution {
public:
    int helper(vector<int>& nums, int start, int end){
        vector<int> dp(nums.size());
        dp[start]= nums[start];
        for(int i=start+1;i<=end;i++){
            int pick= nums[i];
            int not_pick= dp[i-1];
            if(i>=start+2){
                pick+= dp[i-2];
            }
            //cout<< pick<<" "<<not_pick<<endl;
            dp[i]= max(pick,not_pick);
        }
        return dp[end];
    }
    int rob(vector<int>& nums) {
        // 0 - n-2
        // 1 - n-1
        int n= nums.size();
        if(n==1) return nums[0];
        return max(helper(nums,0,n-2), helper(nums,1,n-1));
    }
};