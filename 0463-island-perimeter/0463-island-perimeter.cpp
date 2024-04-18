class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n= grid.size();
        int m= grid[0].size();
        
        int ans=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 1){
                    // up
                    if(i==0){
                        ans++;
                    }
                    else if(grid[i-1][j]==0){
                        ans++;
                    }
                    
                    // down
                    if(i==n-1){
                        ans++;
                    }
                    else if(grid[i+1][j]==0){
                        ans++;
                    }
                    
                    // left
                    if(j==0){
                        ans++;
                    }
                    else if(grid[i][j-1]==0)    ans++;
                    
                    //right
                    if(j==m-1){
                        ans++;
                    }
                    else if(grid[i][j+1]==0)    ans++;
                }
            }
        }
        
        return ans;
    }
};