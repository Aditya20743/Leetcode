class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m= grid.size();
        int n= grid[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        queue< pair<pair<int,int>, int> > q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(!vis[i][j] && grid[i][j]==2){
                    vis[i][j]=1;
                    q.push({{i,j},0});
                }
            }
        }
        int tmax= 0;
        int dir[5]={-1,0,1,0,-1};
        
        while(!q.empty()){
            
            int r= q.front().first.first;
            int c= q.front().first.second;
            int t= q.front().second;
            q.pop();
            
            tmax = max(tmax,t);
            for(int i=0;i<4;i++){
                int nr= r+ dir[i];
                int nc= c+ dir[i+1];
                
                if(nr>=0 && nc>=0 && nr< m && nc< n){
                    if(!vis[nr][nc] && grid[nr][nc]==1){
                        vis[nr][nc]=1;
                        q.push({{nr,nc},t+1});
                    }
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
        return tmax;
    }
};