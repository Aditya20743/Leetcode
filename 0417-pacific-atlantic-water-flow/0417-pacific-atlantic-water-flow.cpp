class Solution {
public:
    void dfs(int r,int c,vector<vector<int>>&v, vector<vector<int>>&heights){
        int m= heights.size();
        int n= heights[0].size();
        
        v[r][c]=1;
        int dir[5]={-1,0,1,0,-1};
        
        for(int i=0;i<4;i++){
            int nr= r+ dir[i];
            int nc= c+ dir[i+1];
            
            if(nr>=0 && nc>=0 && nr<m && nc<n){
                if(heights[nr][nc]>= heights[r][c] && v[nr][nc]==-1){
                    dfs(nr,nc,v,heights);
                }
                // else if(heights[nr][nc]< heights[r][c] && v[nr][nc]==-1){
                //     v[nr][nc]=0;
                // }
            }
        }
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m= heights.size();
        int n= heights[0].size();
        
        // vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> pac(m,vector<int>(n,-1));
        vector<vector<int>> atl(m,vector<int>(n,-1));
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 || j==0){
                    pac[i][j]=1;
                    dfs(i,j,pac,heights);
                }
                if(i==m-1 || j==n-1){
                    atl[i][j]=1;
                    dfs(i,j,atl,heights);
                }
            }
        }
        vector<vector<int>> ans;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<pac[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                cout<<atl[i][j]<<" ";
            }
            cout<<endl;
        }
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(pac[i][j]==1 && atl[i][j]==1){
                    vector<int> t;
                    t.push_back(i);
                    t.push_back(j);
                    ans.push_back(t);
                }
            }
        }
        return ans;
    }
};