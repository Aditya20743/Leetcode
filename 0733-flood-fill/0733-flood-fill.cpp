class Solution {
public:
    int rd[4]={-1,0,1,0};
    int cd[4]={0,1,0,-1};
    
    void dfs(int r, int c, int col, vector<vector<int>>& image, vector<vector<int>> &vis,int original_col){
        int m= image.size();
        int n= image[0].size();
        
        vis[r][c]=1;
        image[r][c]=col;
        
        for(int i=0;i<4;i++){
            int nr= r+ rd[i];
            int nc= c+ cd[i];
            
            if(nr>=0 && nr<m && nc>=0 && nc<n ){
                if(vis[nr][nc]==0 && image[nr][nc]==original_col){
                    //image[nr][nc]=col;
                    //vis[nr][nc]=1;
                    
                    dfs(nr,nc,col,image,vis, original_col);
                }
            }
            
        }
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m= image.size();
        int n= image[0].size();
        
        //int original= 
        
        if(color== image[sr][sc]){
            return image;
        }
        vector<vector<int>> vis(m,vector<int>(n,0));
        
        dfs(sr,sc, color, image, vis, image[sr][sc] );
        return image;
    }
};