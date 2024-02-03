class Solution {
public:
    int helper(int i, vector<int>&arr, int k,vector<int>&dp){
        int n= arr.size();
        if(i>=n)    return 0;
        
        if(dp[i]!= -1)  return dp[i];
        
        int take=0;
        
        int maxi = 0;
        
        for(int j=1;j<=k;j++){
            int nxt= min(i+j, n);
            take = helper(nxt,arr,k,dp)+ (nxt-i)* *max_element(arr.begin()+i,arr.begin()+nxt);
            maxi= max(maxi, take);
        }

        // not_take= helper(i+1,arr,k,dp)+ arr[i];
        
        return dp[i] =maxi;
    }
    
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        vector<int> dp(arr.size(),-1);
        
        return helper(0,arr,k,dp);
    }
};