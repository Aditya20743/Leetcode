class Solution {
public:
    bool helper(int i, vector<int>&col, int color,vector<vector<int>>& graph ){
        col[i] = color;
        
        for(auto it: graph[i]){
            if(col[it]== color){
                return false;
            }
            else if(col[it]== -1){
                if(helper(it, col, !color, graph)== false){
                    return false;
                }
            }
        }
        return true;
        
    }
    
    bool isBipartite(vector<vector<int>>& graph) {
        int n= graph.size();
        
        vector<int> col(n,-1);
        
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(helper(i, col, 1, graph)== false){
                    return false;
                }
            }
        }
        return true;
    }
};