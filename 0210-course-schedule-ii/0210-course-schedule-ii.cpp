class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites){ 
        vector<int> adj[numCourses];
        for(int i=0;i<prerequisites.size();i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        queue<int> q;
        int indeg[numCourses];
        for(int i=0;i<numCourses;i++)   indeg[i]=0;
        
        for(int i=0;i<numCourses;i++){
            for(auto it: adj[i])
                indeg[it]++;
        }
        
        for(int i=0;i<numCourses;i++){
            if(indeg[i]==0) q.push(i);
        }
        
        vector<int> ans;
        while(!q.empty()){
            int n= q.front();
            q.pop();
            ans.push_back(n);
            
            for(auto it: adj[n]){
                indeg[it]--;
                if(indeg[it]==0)    q.push(it);
            }
        }
        if(ans.size() ==numCourses)  return ans; 
            return {};
    }
};