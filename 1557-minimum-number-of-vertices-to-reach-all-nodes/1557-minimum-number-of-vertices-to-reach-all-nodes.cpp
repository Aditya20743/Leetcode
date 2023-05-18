class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<vector<int>> indeg(n);
        for(int i=0;i<edges.size();i++){
            indeg[edges[i][1]].push_back(edges[i][0]);
        }
        int t=0;
        for(auto it: indeg){
            if(it.size()==0){
                ans.push_back(t);
            }
            t++;
        
        }
        return ans;
    }
};