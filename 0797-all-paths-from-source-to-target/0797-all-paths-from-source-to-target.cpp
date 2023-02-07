class Solution {
public:
    void dfs(int src,int tar,vector<vector<int>>& graph,vector<int>&temp,
            vector<vector<int>>&result){
        temp.push_back(src);
        if(src == tar)  result.push_back(temp);
        else{
            for(auto it: graph[src]){
                dfs(it, tar,graph,temp,result);
            } 
        }
        temp.pop_back();
        
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>> result;
        vector<int>temp;
        int n=graph.size();
        
        int src= 0; int tar= n-1;
        dfs(src,tar,graph,temp,result);
        return result;
    }
};