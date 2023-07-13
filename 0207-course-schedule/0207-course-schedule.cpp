class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int count=0;
        
        vector<vector<int>> adj(numCourses);
        
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indeg(numCourses,0);
        
        for(int i=0;i<numCourses;i++){
            for(auto it:adj[i]){
                indeg[it]++;
            }
        }
        int c=0;
        queue<int> q;
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                c++;
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    c++;
                    q.push(it);
                }
            }
        }
        
        return c==numCourses;
    }
};