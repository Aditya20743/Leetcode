class Solution {
public:
    int helper(int y,int ny,vector<vector<int>>& grid){
        int res=0;
        int n=grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        for(int i=0;i<=n/2;i++){
            vis[i][i]=1;
            if(grid[i][i]!= y){
                res++;
            }
            
        }
        for(int i=0;i<n/2;i++){
            vis[i][n-1-i]=1;
            if(grid[i][n-1-i]!= y){
                res++;
                
            }
        }
        
        for(int i=n/2+1;i<n;i++){
            vis[i][n/2]=1;
            if(grid[i][n/2]!= y){
                res++;
                
            }
        }
        // cout<<y<<" "<<res<<endl;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]== 0 && grid[i][j]!= ny){
                    res++;
                    // cout<<grid[i][j]<<" "<<i<<" "<<j<<endl;
                }
            }
        }
        return res;
        
    }
    
    int minimumOperationsToWriteY(vector<vector<int>>& grid) {
        int n=grid.size();
        int c=INT_MAX;
        
        for(int i=0;i<=2;i++){
            for(int j=0;j<=2;j++){
                if(i!= j){
                    c=min(c,helper(i,j,grid));
                }
            }
        }
        
        return c;
    }
};