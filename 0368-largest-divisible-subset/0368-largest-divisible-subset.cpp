class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int last_ind=0,ans=0;
        vector<int> dp(nums.size(),1), hash(nums.size());
        for(int i=0;i<nums.size();i++){
            hash[i]=i;
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0 && dp[i]<dp[j]+1){
                    dp[i]=dp[j]+1;
                    hash[i]=j;
                }
            }
            if(ans<dp[i]){
                ans=dp[i];
                last_ind= i;
            }
        }
        vector<int> v;
        v.push_back(nums[last_ind]);
        while(hash[last_ind]!=last_ind){
            last_ind=hash[last_ind];
            v.push_back(nums[last_ind]);
        }
        reverse(v.begin(),v.end());
        return v;
    }
};