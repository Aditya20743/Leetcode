class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        int steps= 0;
        vector<int> adj[n];
        vector<int> vis(n,0);
        for(int i=0;i<manager.size();i++){
            if(manager[i]!= -1){
                adj[manager[i]].push_back(i);    
            }
        }
        queue<pair<int,int>> q;
        q.push({headID, 0});
        vis[headID]=1;
        
        while(!q.empty()){
            int step= q.front().second;
            int senior= q.front().first;
            q.pop();
            steps =max(step, steps);
            for(auto it: adj[senior]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,step + informTime[senior]});
                }
            }
        }
        return steps;
    }
};