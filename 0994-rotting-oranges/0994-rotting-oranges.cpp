class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        
        queue<pair <pair<int,int>, int> > q;
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                }
            }
        }
        int dir[5]={-1,0,1,0,-1};
        
        int max_t=0;
        
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int t= q.front().second;
            
            max_t= max(t,max_t);
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr= r+ dir[i];
                int nc= c+ dir[i+1];
                if(nr>=0 && nc>=0 && nr<m && nc<n){
                    if(grid[nr][nc]==1 && vis[nr][nc]==0){
                        vis[nr][nc]=1;
                        grid[nr][nc]=2;
                        q.push({{nr,nc},t+1});
                    }
                }
            }
        }
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(vis[i][j]==0 && grid[i][j]==1){
                    return -1;
                }
            }
        }
        return max_t;
    }
};
