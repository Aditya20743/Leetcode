class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        
        if(grid[0][0]==1)   return -1;
        
        vector<vector<int>> vis(n,vector<int>(n,0));
        
        queue<pair<pair<int,int>,int>> q;
        q.push({{0,0},0});
        vis[0][0]=1;
        
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int d= q.front().second;
            
            if(r==n-1 && c== n-1)   return d+1;
            q.pop();
            
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr= r+i;
                    int nc= c+j;
                    if(nr>=0 &&nc>=0 && nr<n &&nc<n && !(i==0 && j==0)){
                        if(grid[nr][nc]==0 && !vis[nr][nc]){
                            q.push({{nr,nc},d+1});
                            vis[nr][nc]=1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};