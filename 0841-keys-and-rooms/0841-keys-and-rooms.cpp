class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n= rooms.size();
        vector<int> vis(n,0);
        
        queue<int> q;
        vis[0]=1;
        for(auto it: rooms[0]){
            if(!vis[it]){
                q.push(it);
                vis[it]=1;
            }
        }
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto it: rooms[node]){
                if(!vis[it]){
                    q.push(it);
                    vis[it]=1;
                }
            }
        }
        for(auto it: vis){
            if(it==0)   return false;
        }
        return true;
    }
};