class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        vector<int> indeg(numCourses,0);
        
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            indeg[prerequisites[i][0]]++;
        }
        
        queue<int> q;
        int c=0;
        
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0){
                q.push(i);
                
            }
        }
        
        while(!q.empty()){
            int node= q.front();
            q.pop();
            c++;
            
            for(auto it: adj[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(c== numCourses){
            return true;
        }
        return false;
    }
};
