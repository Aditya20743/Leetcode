class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        
        queue<pair<pair<int,int>, int>> q;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    q.push({{i,j},0});
                    ans[i][j]=0;
                    vis[i][j]=1;
                }
            }
        }
        
        int dir[5]={-1,0,1,0,-1};
        
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int dis=q.front().second;
            q.pop();
            // vis[i][j]=1;
            
            for(int i=0;i<4;i++){
                int nr= r + dir[i];
                int nc= c + dir[i+1];
                    
                if(nr>=0 && nc>=0 && nr< n && nc< m){
                    if( vis[nr][nc]==0 && mat[nr][nc]==1){
                        q.push({{nr,nc}, dis+1});
                        vis[nr][nc]=1;
                        ans[nr][nc]=dis+1;
                    }
                }
            }
        }
        return ans;
    }
};