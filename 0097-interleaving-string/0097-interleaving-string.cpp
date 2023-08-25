class Solution {
public:
    int helper(int i,int j,int x, string s1, string s2, string s3,vector<vector<int>>&dp){
         if(i==s1.size()){
             while(x!= s3.size()){
                 if(s2[j++]!= s3[x++]){
                     return 0;
                 }
             }
             return 1;
        }
        
        if(j==s2.size()){
             while(x!= s3.size()){
                 if(s1[i++]!= s3[x++]){
                     return 0;
                 }
             }
             return 1;
        }
        if(dp[i][j]!= -1){
            return dp[i][j];
        }
        
        if(s1[i] == s3[x] && s2[j] == s3[x]){
            return dp[i][j]= helper(i+1, j, x+1, s1,s2,s3,dp) || helper(i, j+1, x+1, s1,s2,s3,dp);
        }
        
        else if (s1[i] == s3[x]){
            return dp[i][j]=helper(i+1, j, x+1, s1,s2,s3,dp);
        }
        
        else if(s2[j] == s3[x]){
            return dp[i][j]=helper(i, j+1, x+1, s1,s2,s3,dp);
        }
        
        return dp[i][j]=0;
        
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size()+ s2.size() != s3.size())   return false;
        
        vector<vector<int>> dp(s1.size()+1, vector<int>(s2.size()+1,-1));
        
        return helper(0,0,0,s1,s2,s3,dp);
    }
};