class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m=grid.size();
        int n= grid[0].size();
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 2){
                    q.push({0,{i,j}});
                    vis[i][j]=1;
                }
            }
        }
        
        vector<int> dir= {-1,0,1,0,-1};
        int t_max=0;
                           
        while(!q.empty()){
            int r= q.front().second.first;
            int c= q.front().second.second;
            int t= q.front().first;
            vis[r][c]=1;
            q.pop();
            
            t_max=max(t_max, t);
            
            for(int i=0;i<4;i++){
                int nr= r+ dir[i];
                int nc= c+ dir[i+1];
                
                if(nr>=0 && nc>=0 && nr<m && nc<n && !vis[nr][nc] && grid[nr][nc]==1){
                    q.push({t+1,{nr,nc}});
                    vis[nr][nc]=1;
                }
            }
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return t_max;
    }
};