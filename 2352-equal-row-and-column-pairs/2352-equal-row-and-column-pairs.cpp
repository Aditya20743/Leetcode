class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int row= grid.size();
        int col= grid[0].size();
        
        vector<vector<int>> rows(row) , cols(col);
        
        map< vector<int> ,int> colsmp;
        
        for(int i=0;i<row;i++){
            vector<int> temp;
            for(int j=0;j<col;j++){
                temp.push_back(grid[i][j]);
            }
            rows[i]= temp;
        }
        
        for(int i=0;i<col;i++){
            vector<int> temp;
            for(int j=0;j<row;j++){
                temp.push_back(grid[j][i]);
            }
            cols[i]= temp;
            colsmp[temp]++;
        }
        int ans=0;
        for(int i=0;i<row;i++){
            if(colsmp[rows[i]]>=1){
                ans+= colsmp[rows[i]];
            }
        }
        return ans;
    }
};