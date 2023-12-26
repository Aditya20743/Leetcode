class Solution {
public:
    
    int helper(int n, int t, int k, vector<vector<int>>&dp){
        int mod = 1e9+7;
        
        if(t<0) return 0;
        
        if(n==0 && t==0){
            return 1;
        }
        else if(n==0 || t==0){
            return 0;
        }
        
        if(dp[n][t]!= -1)   return dp[n][t];
        
        long long cnt=0;
        for(int i=1;i<=k;i++){
            long long calc=helper(n-1,t-i,k,dp)%mod; 
            if(calc>0){
                cnt=(cnt%mod+ calc%mod)%mod; 
            }
        }
        return dp[n][t]= (int)cnt%mod;
    }
    int numRollsToTarget(int n, int k, int target) {
        
        
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        
        return helper(n,target,k,dp);
    }
};