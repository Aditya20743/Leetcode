class Solution {
public:
    void bfs(int node,vector<int>&vis ,vector<vector<int>>&bombs , int& c,vector<vector<int>>&adj ){
        vis[node]=1;
        queue<int> q;
        q.push(node);
        c++;
        while(!q.empty()){
            int next= q.front();
            vis[next]=1;
            q.pop();
            
            for(auto it: adj[next]){
                if(!vis[it]){
                    c++;
                    vis[it]=1;
                    q.push(it);
                }
            }
            
        }
    }
    
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n= bombs.size();
        vector<vector<int>> adj(n);
        
        for(int i=0;i<n;i++){
            int x1= bombs[i][0];
            int y1= bombs[i][1];
            for(int j=0;j<n;j++){
                 int x2= bombs[j][0];
                 int y2= bombs[j][1];
                
                long long t= (y2-y1);
                t=t*t;
                long long r= (x2-x1);
                r=r*r;
                long long u= bombs[i][2];
                u=u*u;
                unsigned long long z= t+r;
                 if(z <= u){
                     adj[i].push_back(j);
                 }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int c=0;
            vector<int> vis(n,0);
            vis[i]=1;
            
            bfs(i, vis, bombs, c, adj);
            ans=max(c,ans);
        }
        return ans;
    }
};