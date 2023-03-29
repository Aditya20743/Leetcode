class Solution {
public:
    int helper(int idx, int c, vector<int>& s, vector<vector<int>>&dp){
        if(idx>= s.size())  return 0;
        
        if(dp[idx][c]!= -1) return dp[idx][c];
        
        int pick= s[idx]* (c+1);
        pick+= helper(idx+1,c+1, s,dp);
        
        int not_pick= helper(idx+1,c,s,dp);
        
        return dp[idx][c]=max(pick,not_pick);
    }
    
    int maxSatisfaction(vector<int>& s) {
        sort(s.begin(),s.end());
        int n= s.size()-1;
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // index, count, s,
        return helper(0,0,s,dp);
        
        
//         vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(n+1,vector<int>(2)));
//         dp[0][0][0]=0;
//         dp[0][0][1]=0;
        
//         // for(auto it: s) cout<<it<<" ";
//         // cout<<endl;
        
//         for(int i=0;i<n+1;i++){
//             for(int j=0;j<i+1;j++){
                
//                 int pick=0;
//                 pick= s[i] *(j+1);
//                 if(i>0 && j>0)
//                    pick+= max(dp[i-1][j-1][0],dp[i-1][j-1][1]);
                
//                 dp[i][j][1]= pick;
                
//                 int not_pick= 0;
//                 if(i>0)
//                     not_pick+=max(dp[i-1][j][0],dp[i-1][j][1]);
                
//                 dp[i][j][0]= not_pick;
                
//                 // dp[i][j]= max(pick,not_pick);
//             }
//         }
//         int maxi=0;
//         for(int i=0;i<n+1;i++){
//             maxi=max(max(dp[n][i][0],dp[n][i][1]),maxi);
//         }
//         return maxi;
    }
};