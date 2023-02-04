class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        queue< pair< pair<int,int> ,int >> q;
        
        vector<vector<int>> vis(n,vector<int>(m,0)) , minD = grid;
    
        bool check= false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({{i,j},0});
                    vis[i][j]=1;
                    
                }
                if(minD[i][j]==0){
                    minD[i][j]=INT_MAX;
                    check=true;
                }
            }
        }
        if(check==false)    return -1;
        
        int dir[5]={-1,0,1,0,-1};
        while(!q.empty()){
            int steps=q.front().second;
            int r= q.front().first.first;
            int c= q.front().first.second;
            vis[r][c]=1;
            q.pop();
            steps++;
            for(int i=0;i<4;i++){
                int nr= r+ dir[i];
                int nc= c+ dir[i+1];
                
                if(nr>=0 && nr<n && nc>=0 && nc< m){
                    if(grid[nr][nc]==0 ){
                        minD[nr][nc]= min(steps,minD[nr][nc]);
                        grid[nr][nc]=-1;
                        if(!vis[nr][nc]){
                            vis[nr][nc]=1;
                            q.push({{nr,nc},steps});
                        }
                    }
                }
            }
        }
        
        int ans=0;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(minD[i][j]!=0)
                    ans= max(ans,minD[i][j]);
                }
            }
        return ans == INT_MAX ? -1 : ans;
    }
};