class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        
        vector<vector<int>> dis(m,vector<int>(n,INT_MAX));
        
        
        queue<pair<pair<int,int>, int>> q;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==0){
                    dis[i][j]=0;
                    q.push({{i,j},0});
                }
            }
        }
        
        while(!q.empty()){
            int r= q.front().first.first;
            int c= q.front().first.second;
            int d= q.front().second;
            
            q.pop();
            
            int rd[4]= {-1,0,1,0};
            int cd[4]= {0,1,0,-1};
            
            for(int i=0;i<4;i++){
                int nr= r+ rd[i];
                int nc= c+ cd[i];
                
                if(nr>=0 && nr<m && nc>=0 && nc<n){
                    if(mat[nr][nc]==1 && dis[nr][nc]> d+1 ){
                        dis[nr][nc]= d+1;
                        q.push({{nr,nc},d+1});
                    } 
                }
            } 
        }
        return dis;
    }
};