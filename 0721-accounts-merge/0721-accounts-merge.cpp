class Disjoint{
    public:
    vector<int> size, rank, parent;
    
    Disjoint(int n){
        size.resize(n+1,1);
        rank.resize(n+1,0);
        parent.resize(n+1);
        
        for(int i=0;i<=n;i++){
            parent[i] = i;
        }
    }
    
    int findUparent(int node){
        if(parent[node] == node)    return node;
        return parent[node] = findUparent(parent[node]);
    }
    
    void unionByrank(int u, int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        
        if(ulp_u == ulp_v)  return;
        
        if(rank[ulp_u]> rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    
    void unionBysize(int u,int v){
        int ulp_u = findUparent(u);
        int ulp_v = findUparent(v);
        
        if(ulp_u == ulp_v)  return;
        
        if(size[ulp_u]> size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+= size[ulp_v];
        }
        else if(size[ulp_u] <= size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+= size[ulp_u];
        }
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        Disjoint dsu(n);
        sort(accounts.begin(), accounts.end());
        
        unordered_map<string,int> mapmailnode;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string mail = accounts[i][j];
                if(mapmailnode.find(mail) == mapmailnode.end()){
                    mapmailnode[mail] = i;
                } 
                else{
                    dsu.unionByrank(i,mapmailnode[mail]);
                }
            }
        }
        
        vector<string> mergedmail[n];
        for(auto it: mapmailnode){
            string mail = it.first;
            int node= dsu.findUparent(it.second); // index
            mergedmail[node].push_back(mail);
        }
        
        vector<vector<string>> ans;
        
        for(int i=0;i<n;i++){
            if(mergedmail[i].size() ==0 )   continue;
            sort(mergedmail[i].begin(), mergedmail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto it: mergedmail[i]){
                temp.push_back(it);
            }
            sort(ans.begin(), ans.end());
            ans.push_back(temp);
        }
        return ans;
    }
};