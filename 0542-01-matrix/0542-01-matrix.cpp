class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m= mat.size();
        int n= mat[0].size();
        
        vector<vector<int>> ans(m,vector<int>(n,1e6));
        
        // vector<vector<int>> vis(m,vector<int>(n,-1));
        
        queue<pair<int,pair<int,int>>> q;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]== 0){
                    ans[i][j]=0;
                    q.push({0,{i,j}});
                    // vis[i][j] = 1;
                }
            }
        }
        vector<int> dir={-1,0,1,0,-1};
        
        while(!q.empty()){
            int d= q.front().first;
            int r= q.front().second.first;
            int c= q.front().second.second;
            
            q.pop();
            
            for(int i=0;i<4;i++){
                int nr= r+ dir[i];
                int nc= c+ dir[i+1];
                
                if(nr>=0 && nc>=0 && nr< m && nc< n){
                    // cout<<mat[nr][nc]<<endl;
                    if(ans[nr][nc]> d+1){
                        ans[nr][nc]= d+1;
                        q.push({d+1,{nr,nc}});
                    }
                }
                
                // if(!vis[nr][nc])
            }
        }
        return ans;
    }
};