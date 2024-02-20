class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(n);
        for(auto it: prerequisites){
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> indeg(n,0);
        
        for(auto it: adj){
            for(auto x: it){
                indeg[x]++;   
            }
        }
        
        int count=0;
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indeg[i]==0){
                q.push(i);
            }
        }
        
        while(!q.empty()){
            int s= q.front();
            q.pop();
            count++;
            
            for(auto it: adj[s]){
                indeg[it]--;
                if(indeg[it]==0){
                    q.push(it);
                }
            }
        }
        
        if(count== n){
            return true;
        }
        return false;
    }
};