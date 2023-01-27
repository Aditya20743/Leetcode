class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int V= graph.size();
        vector<int> adj[V];
        
        for(int i=0;i<V;i++){
            for(int j=0;j<graph[i].size();j++){
                adj[graph[i][j]].push_back(i);
            }
        }
        
        int outdeg[V];
        for(int i=0;i<V;i++)    outdeg[i]=0;
        
        for(int i=0;i<V;i++){
            for(auto it: adj[i])
                outdeg[it]++;
        }
        queue<int> q;
        for(int i=0;i<V;i++){
            if(outdeg[i]==0)    q.push(i);
        }
        vector<int> v;
        while(!q.empty()){
            int n=q.front();
            q.pop();
            v.push_back(n);
            for(auto it: adj[n]){
                outdeg[it]--;
                if(outdeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(v.begin(),v.end());
        return v;
        
    }
};