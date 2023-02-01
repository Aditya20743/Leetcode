class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m= image.size();
        int n=image[0].size();
        vector<vector<int>> visited(m,vector<int>(n,0));
        
        queue<pair<int,int>> q;
        q.push({sr,sc});
        int old= image[sr][sc];
        int dir[5]={-1,0,1,0,-1};
        
        if(old == color)    return image;
        
        while(!q.empty()){
            int r= q.front().first;
            int c= q.front().second;
            q.pop();
            visited[r][c]=1;
            image[r][c]=color;
            
            for(int i=0;i<4;i++){
                int nr= r+dir[i];
                int nc= c+dir[i+1];
                
                if(nr>=0 && nc>=0 && nr<m && nc<n && visited[nr][nc]==0 
                   && image[nr][nc]== old){
                    q.push({nr,nc});
                }
            }
        }
        return image;
    }
};