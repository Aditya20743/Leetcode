class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n =graph.size();
        vector<int> revg[n], indeg(n,0);
        
        
        for(int i=0;i<n;i++){
            for( auto it:graph[i]){
                revg[it].push_back(i);
            }
        }
        
        for(int i=0;i<n;i++){
            for(auto it: revg[i]){
                indeg[it]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        vector<int> ans;
        while(!q.empty()){
            int node= q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto it: revg[node]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};