class Solution {
public:
    int lcs(string r, string s){
        int n1= r.size();
        
        vector<vector<int>> dp(n1+1,vector<int>(n1+1,0));
        
        for(int i=1;i<n1+1;i++){
            for(int j=1;j<n1+1;j++){
               if(r[i-1]==s[j-1]){
                  dp[i][j]= 1+dp[i-1][j-1];
               }else{
                   dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
               } 
            }
        }
        return dp[n1][n1];
    }
    
    int minInsertions(string s) {
        // lcs among s, reverse s    s.size()- lcs
        
        string r= s;
        reverse(r.begin(),r.end());
    
        int n=lcs(r,s);
        
        return s.size()- n;
        
    }
};