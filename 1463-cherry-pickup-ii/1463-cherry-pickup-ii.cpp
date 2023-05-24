class Solution {
public:
    int helper(int i,int j1,int j2, int r,int c,vector<vector<int>>& grid, vector<vector<vector<int>>>&dp ){
        
        if(j1<0 || j2<0 || j1>=c ||j2>=c){
            return 0;
        }
        if(dp[i][j1][j2]!= -1)  return dp[i][j1][j2];
        
        if(i== r-1){
            if(j1==j2){
                return grid[i][j1];
            }
            else{
                return grid[i][j1]+ grid[i][j2];
            }
        }
        
        int maxi=0;
        for(int x=-1;x<=1;x++){
            for(int y=-1;y<=1;y++){
                int val=0;
                if(j1==j2){
                    val= grid[i][j1];
                }
                else{
                    val= grid[i][j1]+ grid[i][j2];
                }
                val+= helper(i+1, j1+x, j2+y,r,c,grid,dp);
                maxi= dp[i][j1][j2]=max(maxi,val);
            }
        }
        return maxi;
        
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r= grid.size();
        int c= grid[0].size();
        
    vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        
        return helper(0,0,c-1,r,c,grid,dp);
        
        
    }
};