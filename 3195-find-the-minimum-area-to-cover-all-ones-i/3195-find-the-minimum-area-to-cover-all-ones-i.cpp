class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int heightLow= INT_MAX;
        int heightMax= 0;
        int widthLow = INT_MAX;
        int widthMax = 0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    heightLow = min(i, heightLow);
                    heightMax = max(i, heightMax);
                    widthLow = min(j, widthLow);
                    widthMax = max(j, widthMax);
                }
            }
        }
        
        return (widthMax - widthLow+1)*(heightMax - heightLow+1);
    }
};