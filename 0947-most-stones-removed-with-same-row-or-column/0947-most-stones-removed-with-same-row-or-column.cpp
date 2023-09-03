class Disjoint{
    public:
    vector<int> rank, size, parent;
    
    Disjoint(int n){
        rank.resize(n+1,0);
        size.resize(n+1,1);
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i] = i;
            size[i] =1;
        }
    }
    
    int FindUparent(int node){
        if(parent[node] == node){
            return node;
        }
        return parent[node] = FindUparent(parent[node]);
    }
    
    void UnionByRank(int u, int v){
        int ulp_u = FindUparent(u);
        int ulp_v = FindUparent(v);
        
        if(ulp_u == ulp_v){
            // already connected
            return;
        }
        
        if(rank[ulp_u]> rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u]< rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]++;
        }
    }
    
    void UnionBySize(int u,int v){
        int ulp_u = FindUparent(u);
        int ulp_v = FindUparent(v);
        
        if(ulp_u == ulp_v){
            // already connected
            return;
        }
        
        if(size[ulp_u]> size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_v]+= size[ulp_u];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_u]+= size[ulp_v];
        }
    }
    
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int maxcol =0;
        int maxrow= 0;
        for(auto it: stones){
            maxcol = max(maxcol, it[1]);
            maxrow = max(maxrow, it[0]);
        }
        
        Disjoint dsu(maxrow + maxcol + 1);
        
        unordered_map<int,int> stonenodes;
        
        for(auto it: stones){
            int noderow= it[0];
            int nodecol= it[1] + maxrow + 1;
            
            dsu.UnionBySize(noderow, nodecol);
            stonenodes[noderow] = 1;
            stonenodes[nodecol] = 1;
        }
        int comp = 0;
        for(auto it: stonenodes){
            if(dsu.parent[it.first] == it.first){
                comp++;
            }
        }
        
        return stones.size() - comp; 
    }
};