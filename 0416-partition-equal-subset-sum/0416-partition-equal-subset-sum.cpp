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
        vector<vector<bool>> dp(nums.size()+1,vector<bool>(sum/2+1,false));
        
        sum =sum/2 ;
        for(int i=nums.size()-1;i>=0;i--){
            for(int j=sum;j>=0;j--){
                if(j==sum){
                    dp[i][j]=true;
                }
                else{
                    int take= false, not_take=dp[i+1][j];
                
                    if(j+nums[i]<= sum){
                        take= dp[i+1][j+nums[i]];
                    }
                
                    dp[i][j]= take | not_take;
                }
                
            }
        }
        
         // for(int i=nums.size()-1;i>=0;i--){
         //    for(int j=sum;j>=0;j--){
         //        cout<<dp[i][j]<<" ";
         //    }
         //     cout<<endl;
         // }
        return dp[0][0];
        
        // return helper(0,0, nums,sum/2 ,dp);
    }
};