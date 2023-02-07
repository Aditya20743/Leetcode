class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        
        if(grid[0][0]==1 || grid[n-1][m-1]==1)   return -1;
        if(grid.size()==1)  return 1;   
        vector<vector<int>> vis(n,vector<int>(m,0));
        
        queue<pair<int, pair<int,int> > > q;
        q.push({0,{0,0}});
        
        vis[0][0]=1;
        while(!q.empty()){       
            int steps= q.front().first;
            int r= q.front().second.first;
            int c= q.front().second.second;
            
            q.pop();
            vis[r][c]=1;
        
            for(int i=-1;i<=1;i++){
                for(int j=-1;j<=1;j++){
                    int nr= r+ i;
                    int nc= c+ j;
                    if(nr>=0 && nc>=0 && nr<n && nc<m){
                        if(nr== n-1 && nc== m-1 ){
                            return steps+1+1;
                        }
                        if(grid[nr][nc]==0 && vis[nr][nc]==0){
                            q.push({steps+1,{nr,nc}});
                            vis[nr][nc]=1;
                        }
                    }
                }
            }
        }
        return -1;
    }
};