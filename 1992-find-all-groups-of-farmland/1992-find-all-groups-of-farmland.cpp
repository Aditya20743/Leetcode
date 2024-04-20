class Solution {
public:
    int dir[5] ={-1,0,1,0,-1};
    void dfs(int i,int j, vector<vector<int>>&land, int&li, int &lj, int &ri,int &rj){
        int m = land.size();
        int n = land[0].size();
        
        for(int k=0;k<4;k++){
            int ni = i+dir[k];
            int nj = j+dir[k+1];
            
            if(ni>=0 && ni<m && nj>=0 && nj<n){
                if(land[ni][nj]==1){
                    if(ni<=li){
                        if(ni<li)   li=ni, lj= nj;
                        else lj=min(lj,nj);
                    }
                    if(ni>=ri){
                        if(ni>ri)   ri=ni, rj= nj;
                        else rj=max(rj,nj);
                    }
                    land[ni][nj]=2;
                    dfs(ni,nj, land, li,lj,ri,rj);
                }
            }
        }
    }
    
    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        
        int m = land.size();
        int n = land[0].size();
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(land[i][j] == 1){
                    int li=i,lj=j,ri=i,rj=j;
                    dfs(i,j, land,li,lj,ri,rj);
                    vector<int> boundary = {li,lj,ri,rj};
                    ans.push_back(boundary);
                }
            }
        }
        return ans;
    }
};