class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>& grid, vector<vector<int>>&vis,
            queue<pair<pair<int,int>,int>>&q){
        int n=grid.size();
        vis[r][c]=1;
        int dir[5]={-1,0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr= r+  dir[i];
            int nc= c+ dir[i+1];
            
            if(nr>=0 && nc>=0 && nr<n && nc<n ){
                if(grid[nr][nc]==1 && vis[nr][nc]==0){
                    dfs(nr,nc,grid,vis,q);
                    vis[nr][nc]=1;
                    q.push({{nr,nc},0});
                }
            }
        }
    }
    int shortestBridge(vector<vector<int>>& grid) {
        int n= grid.size();
        vector<vector<int>> vis(n,vector<int>(n,0));
        queue<pair<pair<int,int> , int>> q;
        bool f=false;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1 && f==false){
                    q.push({{i,j},0});
                    dfs(i,j,grid,vis,q);
                    vis[i][j]=1;
                    f=true;
                    break;
                }
            }
            if(f==true)break;
        }
        cout<<q.size();
        int dir[5]={-1,0,1,0,-1};
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int dis= q.front().second;
            vis[r][c]=1;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr= r+ dir[i];
                int nc= c+ dir[i+1];
                if(nr>=0 && nc>=0 && nr< n && nc<n){
                    if(grid[nr][nc]==1 && vis[nr][nc]==0){
                        return dis;
                    }
                    if(vis[nr][nc]==0 && grid[nr][nc]==0){
                        q.push({{nr,nc},dis+1});
                        vis[nr][nc]=1;
                    }
                }
            }
        }
        return -1;
    }
};