class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        int n= edges.size();
        vector<int> v(n+2);
        
        for(auto it: edges){
            v[it[0]]++;
            v[it[1]]++;
        }
        
        for(int i=1;i<n+2;i++){
            
            if(v[i]>1){
                return i;
            }
        }
        return -1;
    }
};