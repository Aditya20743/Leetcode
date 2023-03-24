class Solution {
public:
    
    void dfs(int node,vector<int> uadj[],vector<int> dadj[], int& count,vector<int>&vis){
        vis[node]=1;
       
        for(auto it: uadj[node]){
            if(!vis[it]){
                int prev= node;
                for(int i=0;i<dadj[it].size();i++)
                    if(dadj[it][i]==prev)    count++;
                
                dfs(it,uadj,dadj,count,vis);
                
            }
        }
        
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<int> uadj[n];
        vector<int> dadj[n];
        for(int i=0;i<connections.size();i++){
            uadj[connections[i][0]].push_back(connections[i][1]);
            uadj[connections[i][1]].push_back(connections[i][0]);
        }
        for(int i=0;i<connections.size();i++){
            dadj[connections[i][0]].push_back(connections[i][1]);
        }
        vector<int> vis(n,0);
        int count=0;
        vis[0]=1;
        dfs(0,uadj,dadj,count,vis);
        return n-count-1;
    }
    
    
    // for(auto it: v){
    //     sum+= it;
    // }
};