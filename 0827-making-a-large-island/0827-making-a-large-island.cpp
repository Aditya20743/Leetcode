class DisjointSet {

public:
    vector<int> rank, parent, size;
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node) {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (rank[ulp_u] < rank[ulp_v]) {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u]) {
            parent[ulp_v] = ulp_u;
        }
        else {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v) {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v) return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
private:
    bool isValid(int newr, int newc, int n) {
        return newr >= 0 && newr < n && newc >= 0 && newc < n;
    }
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n * n);
        // step - 1
        for (int row = 0; row < n ; row++) {
            for (int col = 0; col < n ; col++) {
                if (grid[row][col] == 0) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n) && grid[newr][newc] == 1) {
                        int nodeNo = row * n + col;
                        int adjNodeNo = newr * n + newc;
                        ds.unionBySize(nodeNo, adjNodeNo);
                    }
                }
            }
        }
        // step 2
        int mx = 0;
        for (int row = 0; row < n; row++) {
            for (int col = 0; col < n; col++) {
                if (grid[row][col] == 1) continue;
                int dr[] = { -1, 0, 1, 0};
                int dc[] = {0, -1, 0, 1};
                set<int> components;
                for (int ind = 0; ind < 4; ind++) {
                    int newr = row + dr[ind];
                    int newc = col + dc[ind];
                    if (isValid(newr, newc, n)) {
                        if (grid[newr][newc] == 1) {
                            components.insert(ds.findUPar(newr * n + newc));
                        }
                    }
                }
                int sizeTotal = 0;
                for (auto it : components) {
                    sizeTotal += ds.size[it];
                }
                mx = max(mx, sizeTotal + 1);
            }
        }
        for (int cellNo = 0; cellNo < n * n; cellNo++) {
            mx = max(mx, ds.size[ds.findUPar(cellNo)]);
        }
        return mx;
    }
};
// class Disjointset{
//     public:
//     vector<int> rank, size, parent;
    
//     Disjointset(int n){
//         rank.resize(n+1,0);
//         size.resize(n+1,1);
//         parent.resize(n+1);
        
//         for(int i=0;i<=n;i++){
//             parent[i] = i;
//         }
//     }
    
//     int findUparent(int node){
//         if(parent[node] == node)    return node;
//         return parent[node] = findUparent(parent[node]);
//     }
    
//     void unionbysize(int u,int v){
//         int ulp_u = findUparent(u);
//         int ulp_v = findUparent(v);
        
//         if(ulp_u == ulp_v)  return;
        
//         if(size[ulp_u] > size[ulp_v]){
//             size[ulp_u]+= size[ulp_v];
//             parent[ulp_v] = ulp_u;
//         }
//         else{
//             size[ulp_v]+= size[ulp_u];
//             parent[ulp_u] = ulp_v;
//         }
//     }
    
//     void unionbyrank(int u,int v){
//         int ulp_u = findUparent(u);
//         int ulp_v = findUparent(v);
        
//         if(ulp_u == ulp_v)  return;
        
//         if(rank[ulp_u] > rank[ulp_v]){
//             parent[ulp_v] = ulp_u;
//         }
//         else if(rank[ulp_u] < rank[ulp_v]){
//             parent[ulp_u] = ulp_v;
//         }
//         else{
//             parent[ulp_u] = ulp_v;
//             rank[ulp_v]++;
//         }
//     }
// };

// class Solution {
// public:
//     int largestIsland(vector<vector<int>>& grid) {
//         int n= grid.size();
//         Disjointset dsu(n*n);
        
//         int dir[5] = {-1,0,1,0,-1};
        
//         for(int r=0;r<n;r++){
//             for(int c=0;c<n;c++){
//                 if(grid[r][c]==0)   continue;
                
//                 int nodeno= r*n + c;
                
//                 for(int i=0;i<4;i++){
//                     int nr= r+ dir[i];
//                     int nc= c+ dir[i+1];
                    
//                     if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nc][nr]==1){
//                         int adjnodeno = nr*n+nc;
//                         dsu.unionbysize(nodeno, adjnodeno);
//                     }
//                 }
//             }
//         }
        
//         int maxi=0;
        
//         for(int r=0;r<n;r++){
//             for(int c=0;c<n;c++){
//                 if(grid[r][c]==1)   continue;
                
//                 int dir[5] = {-1,0,1,0,-1};
//                 set<int> components;
                
//                 for(int i=0;i<4;i++){
//                     int nr= r+ dir[i];
//                     int nc= c+ dir[i+1];
                    
//                     if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
//                         int adjnodeno= nr*n + nc; 
//                         components.insert( dsu.findUparent(adjnodeno));
//                     }
//                 }
                
//                 int totalsize= 0;
                
//                 for(auto it: components){
//                     totalsize+= dsu.size[it];
//                 }
//                 maxi = max(maxi, totalsize + 1);
//             }
//         }
//         for(int node = 0; node< n*n; node++){
//             maxi = max(maxi, dsu.size[dsu.findUparent(node)]);
//         }
        
//         return maxi;
        
//     }
// };