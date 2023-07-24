class Solution {
public:
    // 1 gaurded 
    // 2 gaurd
    // -1 u
    // 0 wall
    int dir[5] = {-1,0,1,0,-1};
    
    void dfs(int i, int j, vector<vector<int>>& v){
        int m= v.size();
        int n= v[0].size();
        
        if(i>=0 && j>=0 && i<m && j<n &&( v[i][j]== 0)){
            return;
        }
        else if(i>=0 && j>=0 && i<m && j<n && v[i][j]== -1){
            v[i][j] =1;
        }
        // for(int i=0;i<m;i++){
        //     for(int j=0;j<n;j++){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int ni= i;
        while(--ni>=0){
            if(v[ni][j]==0 || v[ni][j]==2)  break;
            v[ni][j]=1;
        }
        ni= i;
        while(++ni<m){
            if(v[ni][j]==0 || v[ni][j]==2)  break;
            v[ni][j]=1;
        }
        int nj= j;
        while(--nj>=0){
            if(v[i][nj]==0 || v[i][nj]==2)  break;
            v[i][nj]=1;
        }
        nj= j;
        while(++nj<n){
            if(v[i][nj]==0 || v[i][nj]==2)  break;
            v[i][nj]=1;
        }
        // for(int x=0;x<4;x++){
        //     int ni= i+ dir[x];
        //     int nj= j+ dir[x+1];
        //     // cout<<1<<endl;
        //     if(ni>= 0 && ni<m && nj>=0 && nj<n){
        //         dfs(ni, nj, v, x);
        //     }
        // }
    }
    
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>> v(m ,vector<int>(n,-1));
        
        for(int i=0;i<walls.size();i++){
            v[walls[i][0]][walls[i][1]] = 0;
        }
        
        for(int i=0;i<guards.size();i++){
            v[guards[i][0]][guards[i][1]]= 2;
        }
        
        for(int i=0;i<guards.size();i++){
            dfs(guards[i][0], guards[i][1], v);
        }
        
        
        int c=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(v[i][j]==-1){
                    c++;
                }
            }
        }
        return c;
    }
};