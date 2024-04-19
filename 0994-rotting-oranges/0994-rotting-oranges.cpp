class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        int n=grid.size();
        int m=grid[0].size();
        
        int fresh=0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        // cout<<fresh<<endl;
        
        if(fresh==0)        return 0;
        int dir[5] = {-1,0,1,0,-1};
        
        int time= -1;
        while(!q.empty()){
            int qs = q.size();
            for(int i=0;i<qs;i++){
                int ri = q.front().first;
                int rj = q.front().second;
                q.pop();
                
                for(int i=0;i<4;i++){
                    int ni = ri+ dir[i];
                    int nj = rj+ dir[i+1];
                    
                    if(ni>=0 && ni<n && nj>=0 && nj<m){
                        if(grid[ni][nj]==1){
                            fresh--;
                            q.push({ni,nj});
                            grid[ni][nj]=2;
                        }
                    }
                }
            }
            time++;
        }
        if(fresh==0)     return time;
        return -1;
        
    }
};