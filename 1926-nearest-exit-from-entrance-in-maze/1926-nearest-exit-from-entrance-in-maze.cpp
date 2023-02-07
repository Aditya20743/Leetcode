class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int m= maze.size();
        int n= maze[0].size();
        
        vector<vector<int>> vis(m,vector<int>(n,0));
        queue<pair<pair<int,int>,int>> q;
        //   { {i,j}, steps==0 }
        int ent_row= entrance[0];
        int ent_col= entrance[1];
        
        if(maze[ent_row][ent_col]=='+') return -1;
        
        q.push({{ent_row,ent_col},0});
        vis[ent_row][ent_col]=1;
        
        int dir[5]={-1,0,1,0,-1};
        
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int step= q.front().second;
            vis[r][c]=1;
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr= r+ dir[i];
                int nc= c+ dir[i+1];
                
                if(nr>=0 && nc>=0 && nr< m && nc< n){
                    if((nr== 0 || nr== m-1 || nc==0 || nc== n-1) && vis[nr][nc]==0){
                        if(maze[nr][nc]=='.')   return step+1;
                    }
                    if(vis[nr][nc]==0 && maze[nr][nc]=='.'){
                        q.push({{nr,nc},step+1});
                        vis[nr][nc]=1;
                    }
                }
            }
        }
        return -1;
        
    }
};