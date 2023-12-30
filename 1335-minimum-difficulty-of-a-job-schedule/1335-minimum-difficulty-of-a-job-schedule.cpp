class Solution {
public:
    
    int helper(int i, vector<int>&jd, int d, vector<vector<int>>&dp){
        if(i>= jd.size()){
            if(d>0) return 1e9;
            return 0;
        }
        if(d<=0) return 1e9;
        
        int diff=1e9;
        
        if(dp[i][d]!= -1)   return dp[i][d];
        
        for(int x=i;x<jd.size();x++){
            int c,take=0;
            for(int j=i;j<=x;j++){
                take = max(jd[j],take);
                c=j;
            }
            
            diff= min(diff,helper(c+1, jd, d-1,dp)+ take );
        }
        return dp[i][d]= diff;   
    }
    
    int minDifficulty(vector<int>& jd, int d) {
//         take one / take 2 /take 3
        if(jd.size()<d){
            return -1;
        }
        
        vector<vector<int>> dp(jd.size()+1, vector<int>(d+1,-1));
        return helper(0, jd, d,dp);
    }
};